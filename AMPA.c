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
 
#define nrn_init _nrn_init__AMPA
#define _nrn_initial _nrn_initial__AMPA
#define nrn_cur _nrn_cur__AMPA
#define _nrn_current _nrn_current__AMPA
#define nrn_jacob _nrn_jacob__AMPA
#define nrn_state _nrn_state__AMPA
#define _net_receive _net_receive__AMPA 
#define kstates kstates__AMPA 
 
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
#define rb1 _p[3]
#define rb1_columnindex 3
#define rb2 _p[4]
#define rb2_columnindex 4
#define rd1d2 _p[5]
#define rd1d2_columnindex 5
#define curr _p[6]
#define curr_columnindex 6
#define g _p[7]
#define g_columnindex 7
#define ina _p[8]
#define ina_columnindex 8
#define ik _p[9]
#define ik_columnindex 9
#define C3 _p[10]
#define C3_columnindex 10
#define C2 _p[11]
#define C2_columnindex 11
#define C1 _p[12]
#define C1_columnindex 12
#define O _p[13]
#define O_columnindex 13
#define D1 _p[14]
#define D1_columnindex 14
#define D2 _p[15]
#define D2_columnindex 15
#define D3 _p[16]
#define D3_columnindex 16
#define DC3 _p[17]
#define DC3_columnindex 17
#define DC2 _p[18]
#define DC2_columnindex 18
#define DC1 _p[19]
#define DC1_columnindex 19
#define DO _p[20]
#define DO_columnindex 20
#define DD1 _p[21]
#define DD1_columnindex 21
#define DD2 _p[22]
#define DD2_columnindex 22
#define DD3 _p[23]
#define DD3_columnindex 23
#define _g _p[24]
#define _g_columnindex 24
#define _nd_area  *_ppvar[0]._pval
#define _ion_ina	*_ppvar[2]._pval
#define _ion_dinadv	*_ppvar[3]._pval
#define _ion_ik	*_ppvar[4]._pval
#define _ion_dikdv	*_ppvar[5]._pval
#define C	*_ppvar[6]._pval
#define _p_C	_ppvar[6]._pval
 
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
 static int hoc_nrnpointerindex =  6;
 /* external NEURON variables */
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
#define Erev Erev_AMPA
 double Erev = 0;
#define Rd3d2 Rd3d2_AMPA
 double Rd3d2 = 12;
#define Rd2d3 Rd2d3_AMPA
 double Rd2d3 = 16;
#define Rd2d1 Rd2d1_AMPA
 double Rd2d1 = 1;
#define Rd1d2 Rd1d2_AMPA
 double Rd1d2 = 0;
#define Rr3 Rr3_AMPA
 double Rr3 = 0.015;
#define Rd3 Rd3_AMPA
 double Rd3 = 0.3;
#define Rr2 Rr2_AMPA
 double Rr2 = 0.0021;
#define Rd2 Rd2_AMPA
 double Rd2 = 0.1;
#define Rr1 Rr1_AMPA
 double Rr1 = 0.15;
#define Rd1 Rd1_AMPA
 double Rd1 = 0.7;
#define Ru2 Ru2_AMPA
 double Ru2 = 10;
#define Rb2 Rb2_AMPA
 double Rb2 = 0;
#define Ru1 Ru1_AMPA
 double Ru1 = 2.4;
#define Rb1 Rb1_AMPA
 double Rb1 = 0;
#define a a_AMPA
 double a = 16;
#define b b_AMPA
 double b = 5;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "Erev_AMPA", "mV",
 "Ru1_AMPA", "/ms",
 "Ru2_AMPA", "/ms",
 "b_AMPA", "/ms",
 "a_AMPA", "/ms",
 "Rd1_AMPA", "/ms",
 "Rr1_AMPA", "/ms",
 "Rd2_AMPA", "/ms",
 "Rr2_AMPA", "/ms",
 "Rd3_AMPA", "/ms",
 "Rr3_AMPA", "/ms",
 "Rd2d1_AMPA", "/ms",
 "Rd2d3_AMPA", "/ms",
 "Rd3d2_AMPA", "/ms",
 "Rb1_AMPA", "/ms",
 "Rb2_AMPA", "/ms",
 "Rd1d2_AMPA", "/ms",
 "gmax", "pS",
 "tdur", "ms",
 "del", "ms",
 "rb1", "/mM",
 "rb2", "/mM",
 "rd1d2", "/mM",
 "curr", "nA",
 "g", "pS",
 "ina", "nA",
 "ik", "nA",
 "C", "mM",
 0,0
};
 static double C10 = 0;
 static double C20 = 0;
 static double C30 = 0;
 static double D30 = 0;
 static double D20 = 0;
 static double D10 = 0;
 static double O0 = 0;
 static double delta_t = 0.01;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "Erev_AMPA", &Erev_AMPA,
 "Ru1_AMPA", &Ru1_AMPA,
 "Ru2_AMPA", &Ru2_AMPA,
 "b_AMPA", &b_AMPA,
 "a_AMPA", &a_AMPA,
 "Rd1_AMPA", &Rd1_AMPA,
 "Rr1_AMPA", &Rr1_AMPA,
 "Rd2_AMPA", &Rd2_AMPA,
 "Rr2_AMPA", &Rr2_AMPA,
 "Rd3_AMPA", &Rd3_AMPA,
 "Rr3_AMPA", &Rr3_AMPA,
 "Rd2d1_AMPA", &Rd2d1_AMPA,
 "Rd2d3_AMPA", &Rd2d3_AMPA,
 "Rd3d2_AMPA", &Rd3d2_AMPA,
 "Rb1_AMPA", &Rb1_AMPA,
 "Rb2_AMPA", &Rb2_AMPA,
 "Rd1d2_AMPA", &Rd1d2_AMPA,
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
 
#define _cvode_ieq _ppvar[7]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"AMPA",
 "gmax",
 "tdur",
 "del",
 "rb1",
 "rb2",
 "rd1d2",
 0,
 "curr",
 "g",
 "ina",
 "ik",
 0,
 "C3",
 "C2",
 "C1",
 "O",
 "D1",
 "D2",
 "D3",
 0,
 "C",
 0};
 static Symbol* _na_sym;
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 25, _prop);
 	/*initialize range parameters*/
 	gmax = 500;
 	tdur = 5;
 	del = 0;
 	rb1 = 1.8;
 	rb2 = 1;
 	rd1d2 = 10;
  }
 	_prop->param = _p;
 	_prop->param_size = 25;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 8, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 	_ppvar[2]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[3]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 prop_ion = need_memb(_k_sym);
 	_ppvar[4]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[5]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
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

 void _AMPA_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("na", -10000.);
 	ion_reg("k", -10000.);
 	_na_sym = hoc_lookup("na_ion");
 	_k_sym = hoc_lookup("k_ion");
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
  hoc_register_prop_size(_mechtype, 25, 8);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
  hoc_register_dparam_semantics(_mechtype, 2, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 6, "pointer");
  hoc_register_dparam_semantics(_mechtype, 7, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 AMPA AMPA.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
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
  /* ~ C1 <-> O ( b , a )*/
 f_flux =  b * C1 ;
 b_flux =  a * O ;
 _RHS1( 1) -= (f_flux - b_flux);
 
 _term =  b ;
 _MATELM1( 1 ,1)  += _term;
 _term =  a ;
 _MATELM1( 1 ,0)  -= _term;
 /*REACTION*/
  /* ~ C2 <-> D1 ( Rd1 , Rr1 )*/
 f_flux =  Rd1 * C2 ;
 b_flux =  Rr1 * D1 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 6) += (f_flux - b_flux);
 
 _term =  Rd1 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 6 ,2)  -= _term;
 _term =  Rr1 ;
 _MATELM1( 2 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ C1 <-> D2 ( Rd2 , Rr2 )*/
 f_flux =  Rd2 * C1 ;
 b_flux =  Rr2 * D2 ;
 _RHS1( 1) -= (f_flux - b_flux);
 _RHS1( 5) += (f_flux - b_flux);
 
 _term =  Rd2 ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 5 ,1)  -= _term;
 _term =  Rr2 ;
 _MATELM1( 1 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ O <-> D3 ( Rd3 , Rr3 )*/
 f_flux =  Rd3 * O ;
 b_flux =  Rr3 * D3 ;
 _RHS1( 4) += (f_flux - b_flux);
 
 _term =  Rd3 ;
 _MATELM1( 4 ,0)  -= _term;
 _term =  Rr3 ;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ D1 <-> D2 ( Rd1d2 , Rd2d1 )*/
 f_flux =  Rd1d2 * D1 ;
 b_flux =  Rd2d1 * D2 ;
 _RHS1( 6) -= (f_flux - b_flux);
 _RHS1( 5) += (f_flux - b_flux);
 
 _term =  Rd1d2 ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 5 ,6)  -= _term;
 _term =  Rd2d1 ;
 _MATELM1( 6 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ D2 <-> D3 ( Rd2d3 , Rd3d2 )*/
 f_flux =  Rd2d3 * D2 ;
 b_flux =  Rd3d2 * D3 ;
 _RHS1( 5) -= (f_flux - b_flux);
 _RHS1( 4) += (f_flux - b_flux);
 
 _term =  Rd2d3 ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 4 ,5)  -= _term;
 _term =  Rd3d2 ;
 _MATELM1( 5 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
   /* C3 + C2 + C1 + D1 + D2 + D3 + O = 1.0 */
 _RHS1(0) =  1.0;
 _MATELM1(0, 0) = 1;
 _RHS1(0) -= O ;
 _MATELM1(0, 4) = 1;
 _RHS1(0) -= D3 ;
 _MATELM1(0, 5) = 1;
 _RHS1(0) -= D2 ;
 _MATELM1(0, 6) = 1;
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
  /* ~ C1 <-> O ( b , a )*/
 f_flux =  b * C1 ;
 b_flux =  a * O ;
 DC1 -= (f_flux - b_flux);
 DO += (f_flux - b_flux);
 
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
  /* ~ O <-> D3 ( Rd3 , Rr3 )*/
 f_flux =  Rd3 * O ;
 b_flux =  Rr3 * D3 ;
 DO -= (f_flux - b_flux);
 DD3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ D1 <-> D2 ( Rd1d2 , Rd2d1 )*/
 f_flux =  Rd1d2 * D1 ;
 b_flux =  Rd2d1 * D2 ;
 DD1 -= (f_flux - b_flux);
 DD2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ D2 <-> D3 ( Rd2d3 , Rd3d2 )*/
 f_flux =  Rd2d3 * D2 ;
 b_flux =  Rd3d2 * D3 ;
 DD2 -= (f_flux - b_flux);
 DD3 += (f_flux - b_flux);
 
 /*REACTION*/
   /* C3 + C2 + C1 + D1 + D2 + D3 + O = 1.0 */
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
  /* ~ C1 <-> O ( b , a )*/
 _term =  b ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 0 ,1)  -= _term;
 _term =  a ;
 _MATELM1( 1 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ C2 <-> D1 ( Rd1 , Rr1 )*/
 _term =  Rd1 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 6 ,2)  -= _term;
 _term =  Rr1 ;
 _MATELM1( 2 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ C1 <-> D2 ( Rd2 , Rr2 )*/
 _term =  Rd2 ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 5 ,1)  -= _term;
 _term =  Rr2 ;
 _MATELM1( 1 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ O <-> D3 ( Rd3 , Rr3 )*/
 _term =  Rd3 ;
 _MATELM1( 0 ,0)  += _term;
 _MATELM1( 4 ,0)  -= _term;
 _term =  Rr3 ;
 _MATELM1( 0 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ D1 <-> D2 ( Rd1d2 , Rd2d1 )*/
 _term =  Rd1d2 ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 5 ,6)  -= _term;
 _term =  Rd2d1 ;
 _MATELM1( 6 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ D2 <-> D3 ( Rd2d3 , Rd3d2 )*/
 _term =  Rd2d3 ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 4 ,5)  -= _term;
 _term =  Rd3d2 ;
 _MATELM1( 5 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
   /* C3 + C2 + C1 + D1 + D2 + D3 + O = 1.0 */
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
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_na_sym, _ppvar, 2, 3);
   nrn_update_ion_pointer(_na_sym, _ppvar, 3, 4);
   nrn_update_ion_pointer(_k_sym, _ppvar, 4, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 5, 4);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  C1 = C10;
  C2 = C20;
  C3 = C30;
  D3 = D30;
  D2 = D20;
  D1 = D10;
  O = O0;
 {
   C3 = 1.0 ;
   C2 = 0.0 ;
   C1 = 0.0 ;
   D1 = 0.0 ;
   D2 = 0.0 ;
   D3 = 0.0 ;
   O = 0.0 ;
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
 initmodel();
  }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   g = gmax * O ;
   curr = 1e-6 * g * ( v - Erev ) ;
   ina = 0.87 * curr ;
   ik = 0.13 * curr ;
   }
 _current += ina;
 _current += ik;

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
 _g = _nrn_current(_v + .001);
 	{ double _dik;
 double _dina;
  _dina = ina;
  _dik = ik;
 _rhs = _nrn_current(_v);
  _ion_dinadv += (_dina - ina)/.001 * 1.e2/ (_nd_area);
  _ion_dikdv += (_dik - ik)/.001 * 1.e2/ (_nd_area);
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina * 1.e2/ (_nd_area);
  _ion_ik += ik * 1.e2/ (_nd_area);
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
 { error = sparse(&_sparseobj1, 7, _slist1, _dlist1, _p, &t, dt, kstates,&_coef1, _linmat1);
 if(error){fprintf(stderr,"at line 84 in file AMPA.mod:\n  SOLVE kstates METHOD sparse\n"); nrn_complain(_p); abort_run(error);}
    if (secondorder) {
    int _i;
    for (_i = 0; _i < 7; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 }  }}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = O_columnindex;  _dlist1[0] = DO_columnindex;
 _slist1[1] = C1_columnindex;  _dlist1[1] = DC1_columnindex;
 _slist1[2] = C2_columnindex;  _dlist1[2] = DC2_columnindex;
 _slist1[3] = C3_columnindex;  _dlist1[3] = DC3_columnindex;
 _slist1[4] = D3_columnindex;  _dlist1[4] = DD3_columnindex;
 _slist1[5] = D2_columnindex;  _dlist1[5] = DD2_columnindex;
 _slist1[6] = D1_columnindex;  _dlist1[6] = DD1_columnindex;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "AMPA.mod";
static const char* nmodl_file_text = 
  "NEURON {\n"
  "    POINT_PROCESS AMPA \n"
  "    RANGE R, gmax, g, ina, ik\n"
  "    USEION na WRITE ina\n"
  "    USEION k WRITE ik\n"
  "    POINTER C \n"
  "    RANGE g, gmax, rb1, rb2, rd1d2, del, tdur, nai0, nao0\n"
  "    RANGE C3, C2, C1, D1,D2, D3, O, curr\n"
  "    GLOBAL Erev\n"
  "    GLOBAL Rb1, Ru1, Rb2, Ru2, a, b, Rd1, Rr1, Rd2, Rr2, Rd3, Rr3, Rd1d2, Rd2d1, Rd2d3, Rd3d2\n"
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
  "}\n"
  "\n"
  "PARAMETER {\n"
  "    Erev = 0 (mV)	: reversal potential\n"
  "    gmax = 500 (pS)	: maximal conductance \n"
  "    tdur = 5 (ms)\n"
  "    del = 0  (ms)	:delay\n"
  "    :nai0 = 15 (mM)\n"
  "    :nao0 = 140 (mM)\n"
  "\n"
  ":Rates \n"
  "\n"
  "  rb1 = 1.8   (/mM /ms)       : binding of glu to C3  			\n"
  "  Ru1 = 2.4  (/ms)	           : unbinding of glu from C3\n"
  "  rb2 = 1   (/mM /ms)          : binding of glu to C2\n"
  "  Ru2 = 10  (/ms)	           : unbinding  of gly from C2\n"
  "  b   = 5 (/ms)	           : opening 		\n"
  "  a   = 16   (/ms)	           : closing \n"
  "  Rd1 = 0.7 (/ms)               : desensitisation C3-D1\n"
  "  Rr1 = 0.15 (/ms)                 : resensitization D1-C3\n"
  "  Rd2 = 0.1 (/ms)              : desensitisation C2-D2\n"
  "  Rr2 = 0.0021 (/ms)               : resensitization D2-C2 \n"
  "  Rd3 = 0.3 (/ms)               : desensitisation O-D3\n"
  "  Rr3 = 0.015 (/ms)                 : resensitization D3-O\n"
  "  rd1d2= 10 (/mM /ms)	:d1 to d2\n"
  "  Rd2d1= 1 (/ms)		:d2 to d1\n"
  "  Rd2d3= 16 (/ms)		:d2 to d3\n"
  "  Rd3d2= 12 (/ms)		:d3 to d2\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "  v		(mV)		: postsynaptic voltage\n"
  "  curr		(nA)		\n"
  "  g 		(pS)					\n"
  "  C (mM) 				\n"
  "  Rb1  (/ms)\n"
  "  Rb2 (/ms)\n"
  "  Rd1d2 (/ms)\n"
  "  ina (nA)\n"
  "  ik(nA)\n"
  "}\n"
  "\n"
  "STATE {		\n"
  "  C3		: unbound\n"
  "  C2		: 1 ligand binds\n"
  "  C1		: 2 ligands bind\n"
  "  O		: Open state\n"
  "  D1		: single ligand, desensitized, from C2\n"
  "  D2       		: desensitized, from C1\n"
  "  D3		: desensitized, from C1\n"
  " }\n"
  "\n"
  "INITIAL {		\n"
  "  C3 = 1\n"
  "  C2 = 0\n"
  "  C1 = 0\n"
  "  D1 = 0\n"
  "  D2 = 0\n"
  "  D3=0\n"
  "  O = 0\n"
  "}\n"
  "\n"
  "BREAKPOINT {			\n"
  "  SOLVE kstates METHOD sparse\n"
  "  g = gmax * O\n"
  "  curr = 1e-6* g * (v - Erev)\n"
  "  ina = 0.87*curr\n"
  "  ik= 0.13*curr\n"
  "}\n"
  "\n"
  "KINETIC kstates {			\n"
  "    Rb1 = rb1 * C\n"
  "    Rb2 = rb2 * C\n"
  "    Rd1d2= rd1d2 * C\n"
  "\n"
  "  ~ C3 <-> C2	(Rb1, Ru1)			\n"
  "  ~ C2 <-> C1	(Rb2, Ru2)\n"
  "  ~ C1 <-> O	(b, a)\n"
  "  ~ C2 <-> D1	(Rd1, Rr1)\n"
  "  ~ C1 <-> D2    	(Rd2, Rr2)\n"
  "  ~ O <-> D3    	(Rd3, Rr3)\n"
  "  ~ D1 <-> D2    	(Rd1d2, Rd2d1)\n"
  "  ~ D2 <-> D3    	(Rd2d3, Rd3d2)\n"
  " \n"
  "  CONSERVE C3+C2+C1+D1+D2+D3+O = 1\n"
  " }\n"
  "\n"
  "\n"
  ;
#endif
