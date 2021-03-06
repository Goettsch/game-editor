#ifndef GDEFS_H
#define GDEFS_H

/* generated by mkdefs; do not edit */

#define Y(i)    (1<<(i))

#define V       0x4      /* NODE         */
#define E       0x5      /* EDGE         */
#define G       0x6      /* GRAPH        */
#define O       0x7      /* OBJECT       */
#define TV      0x8      /* TV_          */
#define YALL    (Y(V)|Y(E)|Y(G))

#define	V_this	    1
#define	V_thisg	    2
#define	V_targt	    3
#define	V_outgraph	    4
#define	V_tgtname	    5
#define	V_infname	    6
#define	V_travroot	    7
#define	V_travtype	    8
#define	V_ARGC	    9
#define	M_degree	   10
#define	M_head	   11
#define	M_tail	   12
#define	M_name	   13
#define	M_indegree	   14
#define	M_outdegree	   15
#define	M_root	   16
#define	M_parent	   17
#define	M_n_edges	   18
#define	M_n_nodes	   19
#define	M_directed	   20
#define	M_strict	   21
#define	T_node	   22
#define	T_edge	   23
#define	T_graph	   24
#define	T_obj	   25
#define	T_tvtyp	   26
#define	A_ARGV	   27
#define	F_graph	   28
#define	F_subg	   29
#define	F_issubg	   30
#define	F_fstsubg	   31
#define	F_nxtsubg	   32
#define	F_node	   33
#define	F_addnode	   34
#define	F_fstnode	   35
#define	F_nxtnode	   36
#define	F_isnode	   37
#define	F_isin	   38
#define	F_edge	   39
#define	F_addedge	   40
#define	F_fstout	   41
#define	F_nxtout	   42
#define	F_fstin	   43
#define	F_nxtin	   44
#define	F_fstedge	   45
#define	F_nxtedge	   46
#define	F_compof	   47
#define	F_index	   48
#define	F_isedge	   49
#define	F_length	   50
#define	F_match	   51
#define	F_write	   52
#define	F_writeg	   53
#define	F_readg	   54
#define	F_fwriteg	   55
#define	F_freadg	   56
#define	F_openf	   57
#define	F_closef	   58
#define	F_readl	   59
#define	F_induce	   60
#define	F_isdirect	   61
#define	F_isstrict	   62
#define	F_delete	   63
#define	F_clone	   64
#define	F_copy	   65
#define	F_copya	   66
#define	F_lock	   67
#define	F_nnodes	   68
#define	F_nedges	   69
#define	F_sqrt	   70
#define	F_cos	   71
#define	F_sin	   72
#define	F_atan2	   73
#define	F_exp	   74
#define	F_pow	   75
#define	F_log	   76
#define	F_xof	   77
#define	F_yof	   78
#define	F_llof	   79
#define	F_urof	   80
#define	F_canon	   81
#define	F_get	   82
#define	F_set	   83
#define	C_flat	   84
#define	C_dfs	   85
#define	C_bfs	   86
#define	C_fwd	   87
#define	C_rev	   88
#define	C_ne	   89
#define	C_en	   90
#define	C_null	   91

#define LAST_V 9
#define LAST_M 21
#define MINNAME 1
#define MAXNAME 91

static Exid_t symbols[] = {
	EXID ( "$", ID, V_this, T_obj, 0),
	EXID ( "$G", ID, V_thisg, T_graph, 0),
	EXID ( "$T", ID, V_targt, T_graph, 0),
	EXID ( "$O", ID, V_outgraph, T_graph, 0),
	EXID ( "$tgtname", ID, V_tgtname, STRING, 0),
	EXID ( "$F", ID, V_infname, STRING, 0),
	EXID ( "$tvroot", ID, V_travroot, T_node, 0),
	EXID ( "$tvtype", ID, V_travtype, T_tvtyp, 0),
	EXID ( "ARGC", ID, V_ARGC, INTEGER, 0),
	EXID ( "degree", ID, M_degree, INTEGER, 0),
	EXID ( "head", ID, M_head, T_node, 0),
	EXID ( "tail", ID, M_tail, T_node, 0),
	EXID ( "name", ID, M_name, STRING, 0),
	EXID ( "indegree", ID, M_indegree, INTEGER, 0),
	EXID ( "outdegree", ID, M_outdegree, INTEGER, 0),
	EXID ( "root", ID, M_root, T_graph, 0),
	EXID ( "parent", ID, M_parent, T_graph, 0),
	EXID ( "n_edges", ID, M_n_edges, INTEGER, 0),
	EXID ( "n_nodes", ID, M_n_nodes, INTEGER, 0),
	EXID ( "directed", ID, M_directed, INTEGER, 0),
	EXID ( "strict", ID, M_strict, INTEGER, 0),
	EXID ( "node_t", DECLARE, T_node, T_node, 0),
	EXID ( "edge_t", DECLARE, T_edge, T_edge, 0),
	EXID ( "graph_t", DECLARE, T_graph, T_graph, 0),
	EXID ( "obj_t", DECLARE, T_obj, T_obj, 0),
	EXID ( "tvtype_t", DECLARE, T_tvtyp, T_tvtyp, 0),
	EXID ( "ARGV", ARRAY, A_ARGV, S|A(1,I), 0),
	EXID ( "graph", FUNCTION, F_graph, G|A(1,S)|A(2,S), 0),
	EXID ( "subg", FUNCTION, F_subg, G|A(1,G)|A(2,S), 0),
	EXID ( "isSubg", FUNCTION, F_issubg, G|A(1,G)|A(2,S), 0),
	EXID ( "fstsubg", FUNCTION, F_fstsubg, G|A(1,G), 0),
	EXID ( "nxtsubg", FUNCTION, F_nxtsubg, G|A(1,G), 0),
	EXID ( "node", FUNCTION, F_node, V|A(1,G)|A(2,S), 0),
	EXID ( "subnode", FUNCTION, F_addnode, V|A(1,G)|A(2,V), 0),
	EXID ( "fstnode", FUNCTION, F_fstnode, V|A(1,G), 0),
	EXID ( "nxtnode", FUNCTION, F_nxtnode, V|A(1,V), 0),
	EXID ( "isNode", FUNCTION, F_isnode, V|A(1,G)|A(2,S), 0),
	EXID ( "isIn", FUNCTION, F_isin, I|A(1,G)|A(2,O), 0),
	EXID ( "edge", FUNCTION, F_edge, E|A(1,V)|A(2,V)|A(3,S), 0),
	EXID ( "subedge", FUNCTION, F_addedge, E|A(1,G)|A(2,E), 0),
	EXID ( "fstout", FUNCTION, F_fstout, E|A(1,V), 0),
	EXID ( "nxtout", FUNCTION, F_nxtout, E|A(1,E), 0),
	EXID ( "fstin", FUNCTION, F_fstin, E|A(1,V), 0),
	EXID ( "nxtin", FUNCTION, F_nxtin, E|A(1,E), 0),
	EXID ( "fstedge", FUNCTION, F_fstedge, E|A(1,V), 0),
	EXID ( "nxtedge", FUNCTION, F_nxtedge, E|A(1,E)|A(2,V), 0),
	EXID ( "compOf", FUNCTION, F_compof, G|A(1,G)|A(2,V), 0),
	EXID ( "index", FUNCTION, F_index, I|A(1,S)|A(2,S), 0),
	EXID ( "isEdge", FUNCTION, F_isedge, E|A(1,V)|A(2,V)|A(3,S), 0),
	EXID ( "length", FUNCTION, F_length, I|A(1,S), 0),
	EXID ( "match", FUNCTION, F_match, I|A(1,S)|A(2,S), 0),
	EXID ( "write", FUNCTION, F_write, I|A(1,G), 0),
	EXID ( "writeG", FUNCTION, F_writeg, I|A(1,G)|A(2,S), 0),
	EXID ( "readG", FUNCTION, F_readg, G|A(1,S), 0),
	EXID ( "fwriteG", FUNCTION, F_fwriteg, I|A(1,G)|A(2,I), 0),
	EXID ( "freadG", FUNCTION, F_freadg, G|A(1,I), 0),
	EXID ( "openF", FUNCTION, F_openf, I|A(1,S)|A(2,S), 0),
	EXID ( "closeF", FUNCTION, F_closef, I|A(1,I), 0),
	EXID ( "readL", FUNCTION, F_readl, S|A(1,I), 0),
	EXID ( "induce", FUNCTION, F_induce, I|A(1,G), 0),
	EXID ( "isDirect", FUNCTION, F_isdirect, I|A(1,G), 0),
	EXID ( "isStrict", FUNCTION, F_isstrict, I|A(1,G), 0),
	EXID ( "delete", FUNCTION, F_delete, I|A(1,G)|A(2,O), 0),
	EXID ( "clone", FUNCTION, F_clone, O|A(1,G)|A(2,O), 0),
	EXID ( "copy", FUNCTION, F_copy, O|A(1,G)|A(2,O), 0),
	EXID ( "copyA", FUNCTION, F_copya, I|A(1,O)|A(2,O), 0),
	EXID ( "lock", FUNCTION, F_lock, I|A(1,G)|A(2,I), 0),
	EXID ( "nNodes", FUNCTION, F_nnodes, I|A(1,G), 0),
	EXID ( "nEdges", FUNCTION, F_nedges, I|A(1,G), 0),
	EXID ( "sqrt", FUNCTION, F_sqrt, F|A(1,F), 0),
	EXID ( "cos", FUNCTION, F_cos, F|A(1,F), 0),
	EXID ( "sin", FUNCTION, F_sin, F|A(1,F), 0),
	EXID ( "atan2", FUNCTION, F_atan2, F|A(1,F)|A(2,F), 0),
	EXID ( "exp", FUNCTION, F_exp, F|A(1,F), 0),
	EXID ( "pow", FUNCTION, F_pow, F|A(1,F)|A(2,F), 0),
	EXID ( "log", FUNCTION, F_log, F|A(1,F), 0),
	EXID ( "xOf", FUNCTION, F_xof, S|A(1,S), 0),
	EXID ( "yOf", FUNCTION, F_yof, S|A(1,S), 0),
	EXID ( "llOf", FUNCTION, F_llof, S|A(1,S), 0),
	EXID ( "urOf", FUNCTION, F_urof, S|A(1,S), 0),
	EXID ( "canon", FUNCTION, F_canon, S|A(1,S), 0),
	EXID ( "aget", FUNCTION, F_get, S|A(1,O)|A(2,S), 0),
	EXID ( "aset", FUNCTION, F_set, I|A(1,O)|A(2,S)|A(3,S), 0),
	EXID ( "TV_flat", CONSTANT, C_flat, T_tvtyp, 0),
	EXID ( "TV_dfs", CONSTANT, C_dfs, T_tvtyp, 0),
	EXID ( "TV_bfs", CONSTANT, C_bfs, T_tvtyp, 0),
	EXID ( "TV_fwd", CONSTANT, C_fwd, T_tvtyp, 0),
	EXID ( "TV_rev", CONSTANT, C_rev, T_tvtyp, 0),
	EXID ( "TV_ne", CONSTANT, C_ne, T_tvtyp, 0),
	EXID ( "TV_en", CONSTANT, C_en, T_tvtyp, 0),
	EXID ( "NULL", CONSTANT, C_null, T_obj, 0),
	EXID ( {0}, 0, 0, 0, 0)
};

static char* typenames[] = {
	"node_t",
	"edge_t",
	"graph_t",
	"obj_t",
	"tvtype_t",
};

typedef unsigned short tctype;

static tctype tchk[][2] = {
	{ 0, 0 },
	{ 0, YALL },
	{ 0, Y(G) },
	{ 0, Y(G) },
	{ 0, Y(G) },
	{ 0, Y(S) },
	{ 0, Y(S) },
	{ 0, Y(V) },
	{ 0, Y(TV) },
	{ 0, Y(I) },
	{ Y(V), Y(I) },
	{ Y(E), Y(V) },
	{ Y(E), Y(V) },
	{ YALL, Y(S) },
	{ Y(V), Y(I) },
	{ Y(V), Y(I) },
	{ YALL, Y(G) },
	{ Y(G), Y(G) },
	{ Y(G), Y(I) },
	{ Y(G), Y(I) },
	{ Y(G), Y(I) },
	{ Y(G), Y(I) },
};

#endif
