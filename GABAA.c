/* Created by Language version: 7.7.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mech_api.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__GABAA
#define _nrn_initial _nrn_initial__GABAA
#define nrn_cur _nrn_cur__GABAA
#define _nrn_current _nrn_current__GABAA
#define nrn_jacob _nrn_jacob__GABAA
#define nrn_state _nrn_state__GABAA
#define _net_receive _net_receive__GABAA 
#define kstates kstates__GABAA 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define gmax _p[0]
#define gmax_columnindex 0
#define tdur _p[1]
#define tdur_columnindex 1
#define del _p[2]
#define del_columnindex 2
#define hco3i _p[3]
#define hco3i_columnindex 3
#define hco3o _p[4]
#define hco3o_columnindex 4
#define rb1 _p[5]
#define rb1_columnindex 5
#define rb2 _p[6]
#define rb2_columnindex 6
#define rd1d2 _p[7]
#define rd1d2_columnindex 7
#define curr _p[8]
#define curr_columnindex 8
#define g _p[9]
#define g_columnindex 9
#define ihco3 _p[10]
#define ihco3_columnindex 10
#define C3 _p[11]
#define C3_columnindex 11
#define C2 _p[12]
#define C2_columnindex 12
#define C1 _p[13]
#define C1_columnindex 13
#define O1 _p[14]
#define O1_columnindex 14
#define O2 _p[15]
#define O2_columnindex 15
#define D1 _p[16]
#define D1_columnindex 16
#define D2 _p[17]
#define D2_columnindex 17
#define ecl _p[18]
#define ecl_columnindex 18
#define ehco3 _p[19]
#define ehco3_columnindex 19
#define icl _p[20]
#define icl_columnindex 20
#define DC3 _p[21]
#define DC3_columnindex 21
#define DC2 _p[22]
#define DC2_columnindex 22
#define DC1 _p[23]
#define DC1_columnindex 23
#define DO1 _p[24]
#define DO1_columnindex 24
#define DO2 _p[25]
#define DO2_columnindex 25
#define DD1 _p[26]
#define DD1_columnindex 26
#define DD2 _p[27]
#define DD2_columnindex 27
#define _g _p[28]
#define _g_columnindex 28
#define _nd_area  *_ppvar[0]._pval
#define _ion_ecl	*_ppvar[2]._pval
#define _ion_icl	*_ppvar[3]._pval
#define _ion_dicldv	*_ppvar[4]._pval
#define C	*_ppvar[5]._pval
#define _p_C	_ppvar[5]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  5;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(Object* _ho) { void* create_point_process(int, Object*);
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt(void*);
 static double _hoc_loc_pnt(void* _vptr) {double loc_point_process(int, void*);
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(void* _vptr) {double has_loc_point(void*);
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(void* _vptr) {
 double get_loc_point_process(void*); return (get_loc_point_process(_vptr));
}
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 0,0
};
 static Member_func _member_func[] = {
 "loc", _hoc_loc_pnt,
 "has_loc", _hoc_has_loc,
 "get_loc", _hoc_get_loc_pnt,
 0, 0
};
 /* declare global and static user variables */
#define Erev Erev_GABAA
 double Erev = 0;
#define Pr Pr_GABAA
 double Pr = 0.3;
#define Rd2d1 Rd2d1_GABAA
 double Rd2d1 = 0.001;
#define Rd1d2 Rd1d2_GABAA
 double Rd1d2 = 0;
#define Rr2 Rr2_GABAA
 double Rr2 = 0.05;
#define Rd2 Rd2_GABAA
 double Rd2 = 0;
#define Rr1 Rr1_GABAA
 double Rr1 = 0.00035;
#define Rd1 Rd1_GABAA
 double Rd1 = 0.006;
#define Ru2 Ru2_GABAA
 double Ru2 = 0.18;
#define Rb2 Rb2_GABAA
 double Rb2 = 0;
#define Ru1 Ru1_GABAA
 double Ru1 = 0.09;
#define Rb1 Rb1_GABAA
 double Rb1 = 0;
#define a2 a2_GABAA
 double a2 = 0.142;
#define a1 a1_GABAA
 double a1 = 1.1;
#define b2 b2_GABAA
 double b2 = 2.5;
#define b1 b1_GABAA
 double b1 = 0.2;
#define dmax dmax_GABAA
 double dmax = 3.6;
#define kh kh_GABAA
 double kh = 2;
#define mV mV_GABAA
 double mV = 0;
#define nh nh_GABAA
 double nh = 2;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "dmax_GABAA", "/ms",
 "kh_GABAA", "mM",
 "Ru1_GABAA", "/ms",
 "Ru2_GABAA", "/ms",
 "b1_GABAA", "/ms",
 "a1_GABAA", "/ms",
 "b2_GABAA", "/ms",
 "a2_GABAA", "/ms",
 "Rd1_GABAA", "/ms",
 "Rr1_GABAA", "/ms",
 "Rr2_GABAA", "/ms",
 "Rd2d1_GABAA", "/ms",
 "Erev_GABAA", "mV",
 "Rb1_GABAA", "/ms",
 "Rb2_GABAA", "/ms",
 "Rd2_GABAA", "/ms",
 "Rd1d2_GABAA", "/ms",
 "gmax", "pS",
 "tdur", "ms",
 "del", "ms",
 "hco3i", "mM",
 "hco3o", "mM",
 "rb1", "/mM",
 "rb2", "/mM",
 "rd1d2", "/mM",
 "curr", "nA",
 "g", "pS",
 "ihco3", "nA",
 "C", "mM",
 0,0
};
 static double C10 = 0;
 static double C20 = 0;
 static double C30 = 0;
 static double D20 = 0;
 static double D10 = 0;
 static double O20 = 0;
 static double O10 = 0;
 static double delta_t = 0.01;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "Pr_GABAA", &Pr_GABAA,
 "dmax_GABAA", &dmax_GABAA,
 "kh_GABAA", &kh_GABAA,
 "nh_GABAA", &nh_GABAA,
 "mV_GABAA", &mV_GABAA,
 "Ru1_GABAA", &Ru1_GABAA,
 "Ru2_GABAA", &Ru2_GABAA,
 "b1_GABAA", &b1_GABAA,
 "a1_GABAA", &a1_GABAA,
 "b2_GABAA", &b2_GABAA,
 "a2_GABAA", &a2_GABAA,
 "Rd1_GABAA", &Rd1_GABAA,
 "Rr1_GABAA", &Rr1_GABAA,
 "Rr2_GABAA", &Rr2_GABAA,
 "Rd2d1_GABAA", &Rd2d1_GABAA,
 "Erev_GABAA", &Erev_GABAA,
 "Rb1_GABAA", &Rb1_GABAA,
 "Rb2_GABAA", &Rb2_GABAA,
 "Rd2_GABAA", &Rd2_GABAA,
 "Rd1d2_GABAA", &Rd1d2_GABAA,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(NrnThread*, _Memb_list*, int);
static void nrn_state(NrnThread*, _Memb_list*, int);
 static void nrn_cur(NrnThread*, _Memb_list*, int);
static void  nrn_jacob(NrnThread*, _Memb_list*, int);
 static void _hoc_destroy_pnt(void* _vptr) {
   destroy_point_process(_vptr);
}
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(NrnThread*, _Memb_list*, int);
static void _ode_matsol(NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[6]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"GABAA",
 "gmax",
 "tdur",
 "del",
 "hco3i",
 "hco3o",
 "rb1",
 "rb2",
 "rd1d2",
 0,
 "curr",
 "g",
 "ihco3",
 0,
 "C3",
 "C2",
 "C1",
 "O1",
 "O2",
 "D1",
 "D2",
 0,
 "C",
 0};
 static Symbol* _cl_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 29, _prop);
 	/*initialize range parameters*/
 	gmax = 28;
 	tdur = 5;
 	del = 0;
 	hco3i = 7;
 	hco3o = 20;
 	rb1 = 30;
 	rb2 = 15;
 	rd1d2 = 1e-08;
  }
 	_prop->param = _p;
 	_prop->param_size = 29;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 7, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_cl_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[2]._pval = &prop_ion->param[0]; /* ecl */
 	_ppvar[3]._pval = &prop_ion->param[3]; /* icl */
 	_ppvar[4]._pval = &prop_ion->param[4]; /* _ion_dicldv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _GABAA_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("cl", -1.0);
 	_cl_sym = hoc_lookup("cl_ion");
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init,
	 hoc_nrnpointerindex, 0,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 29, 7);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
  hoc_register_dparam_semantics(_mechtype, 2, "cl_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cl_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "cl_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "pointer");
  hoc_register_dparam_semantics(_mechtype, 6, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 GABAA GABAA.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 
#define F _nrnunit_F[_nrnunit_use_legacy_]
static double _nrnunit_F[2] = {0x1.78e555060882cp+16, 96485.3}; /* 96485.3321233100141 */
 
#define R _nrnunit_R[_nrnunit_use_legacy_]
static double _nrnunit_R[2] = {0x1.03d3b37125759p+13, 8314.5}; /* 8314.46261815323851 */
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 extern double *_getelm();
 
#define _MATELM1(_row,_col)	*(_getelm(_row + 1, _col + 1))
 
#define _RHS1(_arg) _coef1[_arg + 1]
 static double *_coef1;
 
#define _linmat1  1
 static void* _sparseobj1;
 static void* _cvsparseobj1;
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[7], _dlist1[7]; static double *_temp1;
 static int kstates();
 
static int kstates ()
 {_reset=0;
 {
   double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=1;_i<7;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 Rb1 = rb1 * C ;
   Rb2 = rb2 * C ;
   Rd2 = dmax / ( 1.0 + pow( ( kh / C ) , nh ) ) ;
   Rd1d2 = rd1d2 * C ;
   /* ~ C3 <-> C2 ( Rb1 , Ru1 )*/
 f_flux =  Rb1 * C3 ;
 b_flux =  Ru1 * C2 ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 2) += (f_flux - b_flux);
 
 _term =  Rb1 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  Ru1 ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ C2 <-> C1 ( Rb2 , Ru2 )*/
 f_flux =  Rb2 * C2 ;
 b_flux =  Ru2 * C1 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 
 _term =  Rb2 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  Ru2 ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ C2 <-> O1 ( b1 , a1 )*/
 f_flux =  b1 * C2 ;
 b_flux =  a1 * O1 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 6) += (f_flux - b_flux);
 
 _term =  b1 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 6 ,2)  -= _term;
 _term =  a1 ;
 _MATELM1( 2 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ C1 <-> O2 ( b2 , a2 )*/
 f_flux =  b2 * C1 ;
 b_flux =  a2 * O2 ;
 _RHS1( 1) -= (f_flux - b_flux);
 
 _term =  b2 ;
 _MATELM1( 1 ,1)  += _term;
 _term =  a2 ;
 _MATELM1( 1 ,0)  -= _term;
 /*REACTION*/
  /* ~ C2 <-> D1 ( Rd1 , Rr1 )*/
 f_flux =  Rd1 * C2 ;
 b_flux =  Rr1 * D1 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 5) += (f_flux - b_flux);
 
 _term =  Rd1 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 5 ,2)  -= _term;
 _term =  Rr1 ;
 _MATELM1( 2 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ C1 <-> D2 ( Rd2 , Rr2 )*/
 f_flux =  Rd2 * C1 ;
 b_flux =  Rr2 * D2 ;
 _RHS1( 1) -= (f_flux - b_flux);
 _RHS1( 4) += (f_flux - b_flux);
 
 _term =  Rd2 ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 4 ,1)  -= _term;
 _term =  Rr2 ;
 _MATELM1( 1 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ D1 <-> D2 ( Rd1d2 , Rd2d1 )*/
 f_flux =  Rd1d2 * D1 ;
 b_flux =  Rd2d1 * D2 ;
 _RHS1( 5) -= (f_flux - b_flux);
 _RHS1( 4) += (f_flux - b_flux);
 
 _term =  Rd1d2 ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 4 ,5)  -= _term;
 _term =  Rd2d1 ;
 _MATELM1( 5 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
   /* C3 + C2 + C1 + D1 + D2 + O1 + O2 = 1.0 */
 _RHS1(0) =  1.0;
 _MATELM1(0, 0) = 1;
 _RHS1(0) -= O2 ;
 _MATELM1(0, 6) = 1;
 _RHS1(0) -= O1 ;
 _MATELM1(0, 4) = 1;
 _RHS1(0) -= D2 ;
 _MATELM1(0, 5) = 1;
 _RHS1(0) -= D1 ;
 _MATELM1(0, 1) = 1;
 _RHS1(0) -= C1 ;
 _MATELM1(0, 2) = 1;
 _RHS1(0) -= C2 ;
 _MATELM1(0, 3) = 1;
 _RHS1(0) -= C3 ;
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE ode begin*/
 static int _ode_spec1() {_reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<7;_i++) _p[_dlist1[_i]] = 0.0;}
 Rb1 = rb1 * C ;
 Rb2 = rb2 * C ;
 Rd2 = dmax / ( 1.0 + pow( ( kh / C ) , nh ) ) ;
 Rd1d2 = rd1d2 * C ;
 /* ~ C3 <-> C2 ( Rb1 , Ru1 )*/
 f_flux =  Rb1 * C3 ;
 b_flux =  Ru1 * C2 ;
 DC3 -= (f_flux - b_flux);
 DC2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C2 <-> C1 ( Rb2 , Ru2 )*/
 f_flux =  Rb2 * C2 ;
 b_flux =  Ru2 * C1 ;
 DC2 -= (f_flux - b_flux);
 DC1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C2 <-> O1 ( b1 , a1 )*/
 f_flux =  b1 * C2 ;
 b_flux =  a1 * O1 ;
 DC2 -= (f_flux - b_flux);
 DO1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C1 <-> O2 ( b2 , a2 )*/
 f_flux =  b2 * C1 ;
 b_flux =  a2 * O2 ;
 DC1 -= (f_flux - b_flux);
 DO2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C2 <-> D1 ( Rd1 , Rr1 )*/
 f_flux =  Rd1 * C2 ;
 b_flux =  Rr1 * D1 ;
 DC2 -= (f_flux - b_flux);
 DD1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C1 <-> D2 ( Rd2 , Rr2 )*/
 f_flux =  Rd2 * C1 ;
 b_flux =  Rr2 * D2 ;
 DC1 -= (f_flux - b_flux);
 DD2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ D1 <-> D2 ( Rd1d2 , Rd2d1 )*/
 f_flux =  Rd1d2 * D1 ;
 b_flux =  Rd2d1 * D2 ;
 DD1 -= (f_flux - b_flux);
 DD2 += (f_flux - b_flux);
 
 /*REACTION*/
   /* C3 + C2 + C1 + D1 + D2 + O1 + O2 = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1() {_reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<7;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 Rb1 = rb1 * C ;
 Rb2 = rb2 * C ;
 Rd2 = dmax / ( 1.0 + pow( ( kh / C ) , nh ) ) ;
 Rd1d2 = rd1d2 * C ;
 /* ~ C3 <-> C2 ( Rb1 , Ru1 )*/
 _term =  Rb1 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  Ru1 ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ C2 <-> C1 ( Rb2 , Ru2 )*/
 _term =  Rb2 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  Ru2 ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ C2 <-> O1 ( b1 , a1 )*/
 _term =  b1 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 6 ,2)  -= _term;
 _term =  a1 ;
 _MATELM1( 2 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ C1 <-> O2 ( b2 , a2 )*/
 _term =  b2 ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 0 ,1)  -= _term;
 _term =  a2 ;
 _MATELM1( 1 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ C2 <-> D1 ( Rd1 , Rr1 )*/
 _term =  Rd1 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 5 ,2)  -= _term;
 _term =  Rr1 ;
 _MATELM1( 2 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ C1 <-> D2 ( Rd2 , Rr2 )*/
 _term =  Rd2 ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 4 ,1)  -= _term;
 _term =  Rr2 ;
 _MATELM1( 1 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ D1 <-> D2 ( Rd1d2 , Rd2d1 )*/
 _term =  Rd1d2 ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 4 ,5)  -= _term;
 _term =  Rd2d1 ;
 _MATELM1( 5 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
   /* C3 + C2 + C1 + D1 + D2 + O1 + O2 = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 7;}
 
static void _ode_spec(NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ecl = _ion_ecl;
     _ode_spec1 ();
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 7; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _cvode_sparse(&_cvsparseobj1, 7, _dlist1, _p, _ode_matsol1, &_coef1);
 }
 
static void _ode_matsol(NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ecl = _ion_ecl;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_cl_sym, _ppvar, 2, 0);
   nrn_update_ion_pointer(_cl_sym, _ppvar, 3, 3);
   nrn_update_ion_pointer(_cl_sym, _ppvar, 4, 4);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  C1 = C10;
  C2 = C20;
  C3 = C30;
  D2 = D20;
  D1 = D10;
  O2 = O20;
  O1 = O10;
 {
   C3 = 1.0 ;
   C2 = 0.0 ;
   C1 = 0.0 ;
   D1 = 0.0 ;
   D2 = 0.0 ;
   O1 = 0.0 ;
   O2 = 0.0 ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  ecl = _ion_ecl;
 initmodel();
 }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   ehco3 = log ( hco3i / hco3o ) * ( celsius + 273.15 ) * R / F ;
   Erev = ehco3 + ecl ;
   g = gmax * ( O1 + O2 ) ;
   curr = 1e-6 * g * ( v - Erev ) ;
   ihco3 = Pr * curr ;
   icl = ( 1.0 - Pr ) * curr ;
   }
 _current += icl;
 _current += ihco3;

} return _current;
}

static void nrn_cur(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  ecl = _ion_ecl;
 _g = _nrn_current(_v + .001);
 	{ double _dicl;
  _dicl = icl;
 _rhs = _nrn_current(_v);
  _ion_dicldv += (_dicl - icl)/.001 * 1.e2/ (_nd_area);
 	}
 _g = (_g - _rhs)/.001;
  _ion_icl += icl * 1.e2/ (_nd_area);
 _g *=  1.e2/(_nd_area);
 _rhs *= 1.e2/(_nd_area);
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
double _dtsav = dt;
if (secondorder) { dt *= 0.5; }
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
  ecl = _ion_ecl;
 { error = sparse(&_sparseobj1, 7, _slist1, _dlist1, _p, &t, dt, kstates,&_coef1, _linmat1);
 if(error){fprintf(stderr,"at line 92 in file GABAA.mod:\n  SOLVE kstates METHOD sparse\n"); nrn_complain(_p); abort_run(error);}
    if (secondorder) {
    int _i;
    for (_i = 0; _i < 7; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 } }}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = O2_columnindex;  _dlist1[0] = DO2_columnindex;
 _slist1[1] = C1_columnindex;  _dlist1[1] = DC1_columnindex;
 _slist1[2] = C2_columnindex;  _dlist1[2] = DC2_columnindex;
 _slist1[3] = C3_columnindex;  _dlist1[3] = DC3_columnindex;
 _slist1[4] = D2_columnindex;  _dlist1[4] = DD2_columnindex;
 _slist1[5] = D1_columnindex;  _dlist1[5] = DD1_columnindex;
 _slist1[6] = O1_columnindex;  _dlist1[6] = DO1_columnindex;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "GABAA.mod";
static const char* nmodl_file_text = 
  "NEURON {\n"
  "    POINT_PROCESS GABAA  			\n"
  "    RANGE R, gmax, g\n"
  "    USEION cl READ ecl WRITE icl VALENCE -1 	\n"
  "    NONSPECIFIC_CURRENT ihco3\n"
  "    POINTER C \n"
  "    RANGE rb1, rb2, rd1d2, del, tdur, hco3i, hco3o \n"
  "    RANGE C3, C2, C1, D1, D2, O1, O2, curr \n"
  "    GLOBAL Erev\n"
  "    GLOBAL Rb1, Ru1, Rb2, Ru2, a1, b1, a2, b2, Rd1, Rr1, Rd2, Rr2, Rd1d2, Rd2d1\n"
  "} \n"
  "\n"
  "UNITS {\n"
  "    (nA) = (nanoamp)\n"
  "    (mV) = (millivolt)\n"
  "    (pS) = (picosiemens)\n"
  "    (umho) = (micromho)\n"
  "    (mM) = (milli/litre)\n"
  "    (uM) = (micro/liter)\n"
  "    (mA) = (milliamp)\n"
  "    F = (faraday) (coulomb)\n"
  "    R = (mole k)  (mV-coulomb/degC)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "    celsius = 37 (degC)\n"
  "    gmax = 28 (pS)	: maximal conductance \n"
  "    tdur = 5 (ms)\n"
  "    del = 0 (ms)\n"
  "    hco3i = 7 (mM)\n"
  "    hco3o = 20 (mM)\n"
  "    Pr= 0.3		:permeability of hco3\n"
  "    dmax= 3.6(/ms)	:max desensitisation rate\n"
  "    kh= 2 (mM)	:[GABA] at dmax/2\n"
  "    nh= 2		:hill coefficient\n"
  "    ecl= -70mV\n"
  "\n"
  ":Rates \n"
  "\n"
  "  rb1 = 30   (/mM /ms)       : binding of GABA to C3			\n"
  "  Ru1 = 0.09  (/ms)	           : unbinding of GABA from C3\n"
  "  rb2 = 15   (/mM /ms)          : binding of GABA to C2\n"
  "  Ru2 = 0.18  (/ms)	           : unbinding  of GABA from C2\n"
  "  b1   = 0.2 (/ms)	           : opening (1 ligand, from C2) 		\n"
  "  a1   = 1.1   (/ms)	           : closing \n"
  "  b2   = 2.5 (/ms)	           : opening (2 lignads, from C1) 		\n"
  "  a2   = 0.142  (/ms)	           : closing \n"
  "  Rd1 = 0.006 (/ms)               : desensitisation C3-D1\n"
  "  Rr1 = 3.5e-4 (/ms)                 : resensitization D1-C3\n"
  ":Rd2 accounted for later\n"
  "  Rr2= 0.05 (/ms)\n"
  "  rd1d2= 1e-8 (/mM /ms)	:d1 to d2\n"
  "  Rd2d1= 1e-3 (/ms)		:d2 to d1\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "  v		(mV)		: postsynaptic voltage\n"
  "  Erev		(mV)	\n"
  "  curr		(nA)		\n"
  "  g 		(pS)					:[GABA] \n"
  "  ehco3 (mV)			\n"
  "  C (mM) 				:pointer to give transmitter conc\n"
  "  Rb1  (/ms)\n"
  "  Rb2 (/ms)\n"
  "  Rd2 (/ms)\n"
  "  Rd1d2(/ms)\n"
  "  icl (nA)\n"
  "  ihco3 (nA)\n"
  "}\n"
  "\n"
  "STATE {		\n"
  "  C3		: unbound\n"
  "  C2		: 1 ligand binds\n"
  "  C1		: 2 ligands bind\n"
  "  O1		: Open state, 1 ligand\n"
  "  O2		: Open state, 2 ligands\n"
  "  D1		: 1 ligand, desensitized, from C2\n"
  "  D2       		: 2 ligands, desensitized, from C1\n"
  " }\n"
  "\n"
  "INITIAL {		\n"
  "  C3 = 1\n"
  "  C2 = 0\n"
  "  C1 = 0\n"
  "  D1 = 0\n"
  "  D2 = 0\n"
  "  O1 = 0\n"
  "  O2 = 0\n"
  "}\n"
  "\n"
  "BREAKPOINT {			\n"
  "  SOLVE kstates METHOD sparse\n"
  "  ehco3= log(hco3i/hco3o)*(celsius+ 273.15)*R/F\n"
  "  Erev= ehco3+ecl\n"
  "  g = gmax * (O1+O2)\n"
  "  curr = 1e-6* g * (v - Erev)  \n"
  "  ihco3 = Pr*curr	\n"
  "  icl = (1-Pr)*curr\n"
  "}\n"
  "\n"
  "KINETIC kstates {			\n"
  "    Rb1 = rb1 * C\n"
  "    Rb2 = rb2 * C\n"
  "    Rd2= dmax/(1+ (kh/C)^nh)\n"
  "    Rd1d2= rd1d2 * C\n"
  "\n"
  "  ~ C3 <-> C2	(Rb1, Ru1)			\n"
  "  ~ C2 <-> C1	(Rb2, Ru2)\n"
  "  ~ C2 <-> O1	(b1, a1)\n"
  "  ~ C1 <-> O2	(b2, a2)\n"
  "  ~ C2 <-> D1	(Rd1, Rr1)\n"
  "  ~ C1 <-> D2    	(Rd2, Rr2)\n"
  "  ~ D1 <-> D2    	(Rd1d2, Rd2d1)\n"
  " \n"
  "  CONSERVE C3+C2+C1+D1+D2+O1+O2 = 1\n"
  " }\n"
  ;
#endif
