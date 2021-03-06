/**************************************************************************

Game Editor - The Cross Platform Game Creation Tool
Copyright (C) 2009  Makslane Araujo Rodrigues, http://game-editor.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

If GPL v3 does not work for you, we offer a "non-GPL" license 
More info at http://game-editor.com/License
Be a Game Editor developer: http://game-editor.com/Sharing_Software_Revenues_in_Open_Source

***************************************************************************/


// Envelope.h: interface for the Envelope class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENVELOPE_H__00025586_451C_462A_AF90_0250027A26C1__INCLUDED_)
#define AFX_ENVELOPE_H__00025586_451C_462A_AF90_0250027A26C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "gedString.h"
#include "SDL.h"
#include "system.h"

/*
* MOTMOTH.C -- Motion path implementation.  This provides a simple
* implementation of motions paths as defined by LightWave 3D.
*
* originally by	Allen Hastings
* modified by		Stuart Ferguson
*
*	1/23/96
*/

/*
* A motion tracks 9 channels (x, y, z position, h, p, b rotation angle,
* and x, y, z scale), although this number can vary.  Envelopes work the
* smae way but track only one channel.
*/

#define MAX_CHANNELS 2 //Look Envelope::KeyFrame::ToGP2X() if change max channels
typedef double		 ChanVec[MAX_CHANNELS];

class Envelope  
{
public:
	Envelope();
	virtual ~Envelope();

	int KeyNumber(int frame);	
	void Value(ChanVec f, int frame);	
	void AddKeyFrame(double value, int frame, int iChannel = 0, double tens = 0.0, double cont = 0.0, double bias = 0.0);

	int GetTotalFrames();
	int GetTotalKeys();
	int GetFrame(int nKey);

	bool RemoveKey(int key);
	void SetLinear(int key, bool bLinear);

	const gedString& getName() {return name;};
	
	/*
	* Each KeyFrame in a motion has the value of the channels at that key,
	* tension, contunity and bias spline controls, a linear flag and the
	* frame at which the key is located (step).
	*/
	class STRUCT_PACK KeyFrame
	{
	public:
		ChanVec		 cv;
		double		 tens, cont, bias;
		Uint16		 linear;
		Uint16		 step; /* keyframe */

#ifdef GP2X
	void ToGP2X();
#endif
	};
	
	
	/*
	* A motion is just an array of `keys' KeyFrames and the total number of
	* steps in the motion.
	*/
	typedef struct st_Motion {
		KeyFrame	*keylist;
		int		 keys, steps; 
	} Motion;

private:	
	void MotionCalcStep(ChanVec resVec, double step);
	static void Hermite(double t, double *h1, double *h2, double *h3, double *h4);

protected:
	Motion motion;
	KeyFrame *keys; 

	Uint16 nChannels;
	Uint16	m_KeyFrame;
	Uint16	m_TotalFrame;
	
	ChanVec f_ini;
	gedString name;
};

#endif // !defined(AFX_ENVELOPE_H__00025586_451C_462A_AF90_0250027A26C1__INCLUDED_)
