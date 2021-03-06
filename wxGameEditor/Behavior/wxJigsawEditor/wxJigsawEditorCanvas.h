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


/////////////////////////////////////////////////////////////////////////////
// Name:        wxJigsawEditorCanvas.h
// Purpose:     
// Author:      Volodymir (T-Rex) Tryapichko
// Modified by: 
// Created:     02/03/2008 19:26:49
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXJIGSAWEDITORCANVAS_H_
#define _WXJIGSAWEDITORCANVAS_H_


/*!
 * Includes
 */

////@begin includes
////@end includes
#include <wx/dragimag.h>
#include <wx/generic/dragimgg.h>
#include <wxJigsawShape.h>
#include "wxJigsawEditorView.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxJigsawEditorCanvas;
////@end forward declarations
class wxJigsawEditorDocument;
class wxJigsawShapeGroup;

/*!
 * Control identifiers
 */

////@begin control identifiers
#define SYMBOL_WXJIGSAWEDITORCANVAS_STYLE wxSIMPLE_BORDER
#define SYMBOL_WXJIGSAWEDITORCANVAS_IDNAME ID_WXJIGSAWEDITORCANVAS
#define SYMBOL_WXJIGSAWEDITORCANVAS_SIZE wxSize(100, 100)
#define SYMBOL_WXJIGSAWEDITORCANVAS_POSITION wxDefaultPosition
////@end control identifiers

//Behavior events
BEGIN_DECLARE_EVENT_TYPES()
DECLARE_EVENT_TYPE(wxEVT_BEHAVIOR_BLOCK_SELECTED, wxID_ANY)
END_DECLARE_EVENT_TYPES()

/// \brief Diagram canvas
class wxJigsawEditorCanvas: public wxWindow
{    
    DECLARE_DYNAMIC_CLASS( wxJigsawEditorCanvas )
    DECLARE_EVENT_TABLE()

	/// \brief Top right point of selection rectangle (ported from another project)
	wxPoint m_TR;
	/// \brief Bottom left point of selection rectangle (ported from another project)
	wxPoint m_BL;
	/// \brief Selection rectangle (ported from another project)
	wxRect m_SelectionRect;

	wxBitmap m_HotSpotBitmap;

public:
	/// \brief Hit test result
	enum wxJigsawEditorCanvasHitTest
	{
		/// None
		wxJSEC_HITTEST_NONE,
		/// Shape
		wxJSEC_HITTEST_SHAPE
	};

	/// \brief Mode
	enum wxJigsawEditorCanvasMode
	{
		/// None
		wxJSEC_MODE_NONE,
		/// Dragging
		wxJSEC_MODE_DRAGGING
	};

    /// Constructor
    wxJigsawEditorCanvas();
	/// Constructor
    wxJigsawEditorCanvas(wxWindow* parent, wxWindowID id = wxJigsawEditorCanvas::ID_WXJIGSAWEDITORCANVAS, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(100, 100), long style = wxSIMPLE_BORDER);

    /// Creation
    bool Create(wxWindow* parent, wxWindowID id = wxJigsawEditorCanvas::ID_WXJIGSAWEDITORCANVAS, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(100, 100), long style = wxSIMPLE_BORDER);

    /// Destructor
    ~wxJigsawEditorCanvas();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin wxJigsawEditorCanvas event handler declarations

    /// wxEVT_SIZE event handler for ID_WXJIGSAWEDITORCANVAS
    void OnSize( wxSizeEvent& event );

    /// wxEVT_PAINT event handler for ID_WXJIGSAWEDITORCANVAS
    void OnPaint( wxPaintEvent& event );

    /// wxEVT_IDLE event handler for ID_WXJIGSAWEDITORCANVAS
    void OnIdle( wxIdleEvent& event );

    /// wxEVT_ERASE_BACKGROUND event handler for ID_WXJIGSAWEDITORCANVAS
    void OnEraseBackground( wxEraseEvent& event );

    /// wxEVT_LEFT_DOWN event handler for ID_WXJIGSAWEDITORCANVAS
    void OnLeftDown( wxMouseEvent& event );

    /// wxEVT_LEFT_UP event handler for ID_WXJIGSAWEDITORCANVAS
    void OnLeftUp( wxMouseEvent& event );

    /// wxEVT_LEFT_DCLICK event handler for ID_WXJIGSAWEDITORCANVAS
    void OnLeftDClick( wxMouseEvent& event );

    /// wxEVT_MOTION event handler for ID_WXJIGSAWEDITORCANVAS
    void OnMotion( wxMouseEvent& event );

////@end wxJigsawEditorCanvas event handler declarations

	/// wxEVT_SCROLL_LINEUP event handler for ID_WXJIGSAWEDITORCANVAS
	void OnScrollLineUp(wxScrollWinEvent & event);
	/// wxEVT_SCROLL_LINEDOWN event handler for ID_WXJIGSAWEDITORCANVAS
	void OnScrollLineDown(wxScrollWinEvent & event);
	/// wxEVT_SCROLL_PAGEUP event handler for ID_WXJIGSAWEDITORCANVAS
	void OnScrollPageUp(wxScrollWinEvent & event);
	/// wxEVT_SCROLL_PAGEDOWN event handler for ID_WXJIGSAWEDITORCANVAS
	void OnScrollPageDown(wxScrollWinEvent & event);
	/// wxEVT_SCROLL_THUMBTRACK event handler for ID_WXJIGSAWEDITORCANVAS
	void OnScrollThumbTrack(wxScrollWinEvent & event);
	/// wxEVT_SCROLL_THUMBRELEASE event handler for ID_WXJIGSAWEDITORCANVAS
	void OnScrollThumbRelease(wxScrollWinEvent & event);

////@begin wxJigsawEditorCanvas member function declarations

	void MotionUpdate(wxPoint currentPos);

    wxJigsawEditorView * GetView() const { return m_View ; }
    void SetView(wxJigsawEditorView * value) { m_View = value ; }

    wxJigsawShapeGroup * GetSelectedObject() const { return m_SelectedObject ; }
	wxJigsawShape * GetSelectedShape() const { return m_SelectedShape;}
    void SetSelectedObject(wxJigsawShapeGroup * value);
	void SetSelectedShape(wxJigsawShape * value);

    wxJigsawEditorCanvasMode GetMode() const { return m_Mode ; }
    void SetMode(wxJigsawEditorCanvasMode value) { m_Mode = value ; }

    wxSize GetSelectedObjectOffset() const { return m_SelectedObjectOffset ; }
    void SetSelectedObjectOffset(wxSize value) { m_SelectedObjectOffset = value ; }

    wxDragImage * GetDragImage() const { return m_DragImage ; }
    void SetDragImage(wxDragImage * value) { m_DragImage = value ; }

    wxJigsawHotSpotArray GetHotSpots() const { return m_HotSpots ; }
    void SetHotSpots(wxJigsawHotSpotArray value) { m_HotSpots = value ; }

    wxJigsawHotSpot * GetActiveHotSpot() const { return m_ActiveHotSpot ; }
    void SetActiveHotSpot(wxJigsawHotSpot * value) { m_ActiveHotSpot = value ; }

    bool GetUpdateLayoutOnPaint() const { return m_UpdateLayoutOnPaint ; }
    void SetUpdateLayoutOnPaint(bool value) { m_UpdateLayoutOnPaint = value ; }

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxJigsawEditorCanvas member function declarations
	/// \brief Returns the pointer to wxJigsawEditorDocument obtained from m_View
	wxJigsawEditorDocument * GetDocument();

	/// \brief Converts client point to logical point
	/// \param pos point
	wxPoint PointToViewPoint(const wxPoint & pos);

	/// \brief Retrieves the code of area under specified position (in logical coordinates)
	/// \param pos point
	wxJigsawEditorCanvasHitTest HitTest(const wxPoint & pos, wxJigsawShape::wxJigsawShapeHitTestInfo & info,
		wxJigsawShapeGroup * ignoreGroup);

	/// \brief Returns the shape under specified point
	/// \param pos point
	wxJigsawShape * GetShapeFromPoint(const wxPoint & pos,
		wxJigsawShapeGroup * ignoreGroup);

	wxJigsawShape::wxJigsawShapeHitTestInfo &GetSelectedShapeInfo() {return infoSelectedShape;}

    /// Should we show tooltips?
    static bool ShowToolTips();

	/// \brief Changes the cursor
	/// \param pos current logical position of mouse pointer
	void UpdateCursor(const wxPoint & pos);

	/// \brief Returns scroll position
	wxPoint GetScrollPosition();

	/// \brief Returns the size of diagram
	wxSize GetDiagramSize();

	/// \brief Returns the rectange which represents visible area
	/// \param scrollPos current scrolling position
	wxRect GetDisplayRect(const wxPoint & scrollPos);
    
	/// \brief Recreates scroll bars
    void AdjustScrollBars();
	/// \brief Changes the view offset
	void FixViewOffset();
	/// \brief Scrolls to specified position
	/// \param new scroll position
	void Scroll(const wxPoint & pt);
	/// \brief Automatically performs scrolling if needed
	/// \param currentPos current mouse position
	/// \param scrollPos current scroll position
	bool AutoScroll(const wxPoint & currentPos, const wxPoint & scrollPos);

	bool CreateDragImage(wxJigsawShape * shape);
	void DestroyDragImage();
	wxJigsawShape *GetDragShape() const;

	void ShowDragImage(bool value);
	void MoveDragImage(const wxPoint & pos, const wxSize & offset);
	void ProcessDrop(const wxPoint & pos, 
		const wxJigsawShape * shape, 
		const wxSize & hotSpotOffset);
	wxJigsawHotSpot * GetHotSpotByPoint(const wxPoint & pos, wxJigsawShapeGroup * targetGroup) const;
	void ReCreateHotSpots();
	void FixActiveHotSpot(const wxPoint & currentPos);
	void ReCreateHotSpotBitmap();
	void DrawHotSpot(wxDC * dc, double scale);

	double GetScale() const;
	void SetScale(double value);

	wxFont GetScaledFont();
	void RefreshBuffer();

	wxDC & GetDoubleBufferDC() {return m_DoubleBufferDC;}

////@begin wxJigsawEditorCanvas member variables
    wxJigsawEditorView * m_View;
    wxJigsawShapeGroup * m_SelectedObject;
	wxJigsawShape * m_SelectedShape;
    wxJigsawEditorCanvasMode m_Mode;
    wxSize m_SelectedObjectOffset;
    wxDragImage * m_DragImage;
    wxJigsawHotSpotArray m_HotSpots;
    wxJigsawHotSpot * m_ActiveHotSpot;
	wxPoint m_MouseDownPos;
    bool m_UpdateLayoutOnPaint;
	wxJigsawShape::wxJigsawShapeHitTestInfo infoSelectedShape;
    /// Control identifiers
    enum {
        ID_WXJIGSAWEDITORCANVAS = 10001
    };
////@end wxJigsawEditorCanvas member variables
	/// \brief Increment for scrolling
	static int ScrollIncrement;
private:
	wxBitmap m_DoubleBufferBitmap;
	wxMemoryDC m_DoubleBufferDC;
};

#endif
    // _WXJIGSAWEDITORCANVAS_H_
