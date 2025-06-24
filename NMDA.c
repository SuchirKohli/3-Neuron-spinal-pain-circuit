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
 
#define nrn_init _nrn_init__NMDA
#define _nrn_initial _nrn_initial__NMDA
#define nrn_cur _nrn_cur__NMDA
#define _nrn_current _nrn_current__NMDA
#define nrn_jacob _nrn_jacob__NMDA
#define nrn_state _nrn_state__NMDA
#define _net_receive _net_receive__NMDA 
#define kstates kstates__NMDA 
 
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
#define tr2 _p[3]
#define tr2_columnindex 3
#define rb1 _p[4]
#define rb1_columnindex 4
#define rb2 _p[5]
#define rb2_columnindex 5
#define Mg _p[6]
#define Mg_columnindex 6
#define K0 _p[7]
#define K0_columnindex 7
#define delta _p[8]
#define delta_columnindex 8
#define curr _p[9]
#define curr_columnindex 9
#define g _p[10]
#define g_columnindex 10
#define ica _p[11]
#define ica_columnindex 11
#define ina _p[12]
#define ina_columnindex 12
#define ik _p[13]
#define ik_columnindex 13
#define C3 _p[14]
#define C3_columnindex 14
#define C2 _p[15]
#define C2_columnindex 15
#define C1 _p[16]
#define C1_columnindex 16
#define O1 _p[17]
#define O1_columnindex 17
#define O2 _p[18]
#define O2_columnindex 18
#define D1 _p[19]
#define D1_columnindex 19
#define D2 _p[20]
#define D2_columnindex 20
#define MB _p[21]
#define MB_columnindex 21
#define DC3 _p[22]
#define DC3_columnindex 22
#define DC2 _p[23]
#define DC2_columnindex 23
#define DC1 _p[24]
#define DC1_columnindex 24
#define DO1 _p[25]
#define DO1_columnindex 25
#define DO2 _p[26]
#define DO2_columnindex 26
#define DD1 _p[27]
#define DD1_columnindex 27
#define DD2 _p[28]
#define DD2_columnindex 28
#define _g _p[29]
#define _g_columnindex 29
#define _nd_area  *_ppvar[0]._pval
#define _ion_ina	*_ppvar[2]._pval
#define _ion_dinadv	*_ppvar[3]._pval
#define _ion_ica	*_ppvar[4]._pval
#define _ion_dicadv	*_ppvar[5]._pval
#define _ion_ik	*_ppvar[6]._pval
#define _ion_dikdv	*_ppvar[7]._pval
#define C	*_ppvar[8]._pval
#define _p_C	_ppvar[8]._pval
 
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
 static int hoc_nrnpointerindex =  8;
 /* external NEURON variables */
 /* declaration of user functions */
 static double _hoc_MgBlock(void*);
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
 "MgBlock", _hoc_MgBlock,
 0, 0
};
#define MgBlock MgBlock_NMDA
 extern double MgBlock( double );
 /* declare global and static user variables */
#define Erev Erev_NMDA
 double Erev = 0;
#define Ro2 Ro2_NMDA
 double Ro2 = 1.62;
#define Ro1 Ro1_NMDA
 double Ro1 = 0.74;
#define Rd2 Rd2_NMDA
 double Rd2 = 0.006;
#define Rd1 Rd1_NMDA
 double Rd1 = 0.008;
#define Rr2 Rr2_NMDA
 double Rr2 = 0.038;
#define Rr1 Rr1_NMDA
 double Rr1 = 0.0005;
#define Rb2 Rb2_NMDA
 double Rb2 = 0;
#define Ru2 Ru2_NMDA
 double Ru2 = 1.434;
#define Ru1 Ru1_NMDA
 double Ru1 = 0.06;
#define Rb1 Rb1_NMDA
 double Rb1 = 0;
#define T T_NMDA
 double T = 37;
#define a a_NMDA
 double a = 0.72;
#define b b_NMDA
 double b = 3.67;
#define z z_NMDA
 double z = 2;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "Erev_NMDA", "mV",
 "Ru1_NMDA", "/ms",
 "Ru2_NMDA", "/ms",
 "b_NMDA", "/ms",
 "a_NMDA", "/ms",
 "Ro2_NMDA", "/ms",
 "Ro1_NMDA", "/ms",
 "Rd1_NMDA", "/ms",
 "Rr1_NMDA", "/ms",
 "Rd2_NMDA", "/ms",
 "Rr2_NMDA", "/ms",
 "T_NMDA", "degC",
 "Rb1_NMDA", "/ms",
 "Rb2_NMDA", "/ms",
 "gmax", "pS",
 "tdur", "ms",
 "del", "ms",
 "tr2", "mM",
 "rb1", "/mM",
 "rb2", "/mM",
 "Mg", "mM",
 "K0", "mM",
 "curr", "nA",
 "g", "pS",
 "ica", "nA",
 "ina", "nA",
 "ik", "nA",
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
 "Erev_NMDA", &Erev_NMDA,
 "Ru1_NMDA", &Ru1_NMDA,
 "Ru2_NMDA", &Ru2_NMDA,
 "b_NMDA", &b_NMDA,
 "a_NMDA", &a_NMDA,
 "Ro2_NMDA", &Ro2_NMDA,
 "Ro1_NMDA", &Ro1_NMDA,
 "Rd1_NMDA", &Rd1_NMDA,
 "Rr1_NMDA", &Rr1_NMDA,
 "Rd2_NMDA", &Rd2_NMDA,
 "Rr2_NMDA", &Rr2_NMDA,
 "T_NMDA", &T_NMDA,
 "z_NMDA", &z_NMDA,
 "Rb1_NMDA", &Rb1_NMDA,
 "Rb2_NMDA", &Rb2_NMDA,
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
 
#define _cvode_ieq _ppvar[9]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"NMDA",
 "gmax",
 "tdur",
 "del",
 "tr2",
 "rb1",
 "rb2",
 "Mg",
 "K0",
 "delta",
 0,
 "curr",
 "g",
 "ica",
 "ina",
 "ik",
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
 static Symbol* _na_sym;
 static Symbol* _ca_sym;
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
 	_p = nrn_prop_data_alloc(_mechtype, 30, _prop);
 	/*initialize range parameters*/
 	gmax = 48;
 	tdur = 5;
 	del = 0;
 	tr2 = 0.1;
 	rb1 = 0.257;
 	rb2 = 0.775;
 	Mg = 1;
 	K0 = 4.1;
 	delta = 0.8;
  }
 	_prop->param = _p;
 	_prop->param_size = 30;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 10, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 	_ppvar[2]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[3]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 prop_ion = need_memb(_ca_sym);
 	_ppvar[4]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[5]._pval = &prop_ion->param[4]; /* _ion_dicadv */
 prop_ion = need_memb(_k_sym);
 	_ppvar[6]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[7]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
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

 void _NMDA_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("na", -10000.);
 	ion_reg("ca", -10000.);
 	ion_reg("k", -10000.);
 	_na_sym = hoc_lookup("na_ion");
 	_ca_sym = hoc_lookup("ca_ion");
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
  hoc_register_prop_size(_mechtype, 30, 10);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
  hoc_register_dparam_semantics(_mechtype, 2, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 6, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 7, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 8, "pointer");
  hoc_register_dparam_semantics(_mechtype, 9, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 NMDA NMDA.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 
#define R _nrnunit_R[_nrnunit_use_legacy_]
static double _nrnunit_R[2] = {0x1.03d3b37125759p+13, 8314.5}; /* 8314.46261815323851 */
 
#define F _nrnunit_F[_nrnunit_use_legacy_]
static double _nrnunit_F[2] = {0x1.78e555060882cp+16, 96485.3}; /* 96485.3321233100141 */
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
   Rb2 = rb2 * tr2 ;
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
  /* ~ C1 <-> O1 ( b , a )*/
 f_flux =  b * C1 ;
 b_flux =  a * O1 ;
 _RHS1( 1) -= (f_flux - b_flux);
 _RHS1( 6) += (f_flux - b_flux);
 
 _term =  b ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 6 ,1)  -= _term;
 _term =  a ;
 _MATELM1( 1 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ O1 <-> O2 ( Ro2 , Ro1 )*/
 f_flux =  Ro2 * O1 ;
 b_flux =  Ro1 * O2 ;
 _RHS1( 6) -= (f_flux - b_flux);
 
 _term =  Ro2 ;
 _MATELM1( 6 ,6)  += _term;
 _term =  Ro1 ;
 _MATELM1( 6 ,0)  -= _term;
 /*REACTION*/
  /* ~ C3 <-> D1 ( Rd1 , Rr1 )*/
 f_flux =  Rd1 * C3 ;
 b_flux =  Rr1 * D1 ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 5) += (f_flux - b_flux);
 
 _term =  Rd1 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 5 ,3)  -= _term;
 _term =  Rr1 ;
 _MATELM1( 3 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ C2 <-> D2 ( Rd2 , Rr2 )*/
 f_flux =  Rd2 * C2 ;
 b_flux =  Rr2 * D2 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 4) += (f_flux - b_flux);
 
 _term =  Rd2 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 4 ,2)  -= _term;
 _term =  Rr2 ;
 _MATELM1( 2 ,4)  -= _term;
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
 
double MgBlock (  double _lv ) {
   double _lMgBlock;
 MB = 1.0 / ( 1.0 + ( Mg / K0 ) * exp ( ( - z ) * delta * F * _lv / R / ( T + 273.15 ) ) ) ;
   
return _lMgBlock;
 }
 
static double _hoc_MgBlock(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  MgBlock (  *getarg(1) );
 return(_r);
}
 
/*CVODE ode begin*/
 static int _ode_spec1() {_reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<7;_i++) _p[_dlist1[_i]] = 0.0;}
 Rb1 = rb1 * C ;
 Rb2 = rb2 * tr2 ;
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
  /* ~ C1 <-> O1 ( b , a )*/
 f_flux =  b * C1 ;
 b_flux =  a * O1 ;
 DC1 -= (f_flux - b_flux);
 DO1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ O1 <-> O2 ( Ro2 , Ro1 )*/
 f_flux =  Ro2 * O1 ;
 b_flux =  Ro1 * O2 ;
 DO1 -= (f_flux - b_flux);
 DO2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C3 <-> D1 ( Rd1 , Rr1 )*/
 f_flux =  Rd1 * C3 ;
 b_flux =  Rr1 * D1 ;
 DC3 -= (f_flux - b_flux);
 DD1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C2 <-> D2 ( Rd2 , Rr2 )*/
 f_flux =  Rd2 * C2 ;
 b_flux =  Rr2 * D2 ;
 DC2 -= (f_flux - b_flux);
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
 Rb2 = rb2 * tr2 ;
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
  /* ~ C1 <-> O1 ( b , a )*/
 _term =  b ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 6 ,1)  -= _term;
 _term =  a ;
 _MATELM1( 1 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ O1 <-> O2 ( Ro2 , Ro1 )*/
 _term =  Ro2 ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 0 ,6)  -= _term;
 _term =  Ro1 ;
 _MATELM1( 6 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ C3 <-> D1 ( Rd1 , Rr1 )*/
 _term =  Rd1 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 5 ,3)  -= _term;
 _term =  Rr1 ;
 _MATELM1( 3 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ C2 <-> D2 ( Rd2 , Rr2 )*/
 _term =  Rd2 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 4 ,2)  -= _term;
 _term =  Rr2 ;
 _MATELM1( 2 ,4)  -= _term;
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
   nrn_update_ion_pointer(_ca_sym, _ppvar, 4, 3);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 5, 4);
   nrn_update_ion_pointer(_k_sym, _ppvar, 6, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 7, 4);
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
 initmodel();
   }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   MgBlock ( _threadargscomma_ v ) ;
   g = gmax * ( O1 + O2 ) ;
   curr = ( 1e-6 ) * MB * g * ( v - Erev ) ;
   ica = 0.816 * curr ;
   ina = 0.15 * curr ;
   ik = 0.06 * curr ;
   }
 _current += ina;
 _current += ica;
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
 double _dica;
 double _dina;
  _dina = ina;
  _dica = ica;
  _dik = ik;
 _rhs = _nrn_current(_v);
  _ion_dinadv += (_dina - ina)/.001 * 1.e2/ (_nd_area);
  _ion_dicadv += (_dica - ica)/.001 * 1.e2/ (_nd_area);
  _ion_dikdv += (_dik - ik)/.001 * 1.e2/ (_nd_area);
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina * 1.e2/ (_nd_area);
  _ion_ica += ica * 1.e2/ (_nd_area);
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
 if(error){fprintf(stderr,"at line 96 in file NMDA.mod:\n  SOLVE kstates METHOD sparse\n"); nrn_complain(_p); abort_run(error);}
    if (secondorder) {
    int _i;
    for (_i = 0; _i < 7; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 }   }}
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
static const char* nmodl_filename = "NMDA.mod";
static const char* nmodl_file_text = 
  "NEURON {\n"
  "  POINT_PROCESS NMDA		\n"
  "  USEION na WRITE ina \n"
  "  USEION ca WRITE ica\n"
  "  USEION k WRITE ik \n"
  "  POINTER C\n"
  "  RANGE C3, C2, C1, D1, D2, O1, O2, curr, ica, ina, ik\n"
  "  RANGE g, gmax, rb1, rb2, tr2, del, tdur, nai0, nao0, cai0, cao0, Mg, K0, delta\n"
  "  GLOBAL Erev\n"
  "  GLOBAL Rb1, Ru1, Ru2, Rb2, a, b, Rr1, Rr2, Rd1, Rd2, Ro1, Ro2 \n"
  "}\n"
  "\n"
  "UNITS {\n"
  "  (nA) = (nanoamp)\n"
  "  (mV) = (millivolt)\n"
  "  (pS) = (picosiemens)\n"
  "  (umho) = (micromho)\n"
  "  (mM) = (milli/liter)\n"
  "  (uM) = (micro/liter)\n"
  "  (mA) = (milliamp)\n"
  "  R= (mole k) (mV-coulomb/degC)\n"
  "  F= (faraday) (coulomb)\n"
  "}\n"
  ":check all values\n"
  "PARAMETER {\n"
  "  Erev	= 0    (mV)		: reversal potential\n"
  "  gmax	=  48 (pS)	: maximal conductance, too high?\n"
  "  tdur = 5 (ms)\n"
  "  del =  0 (ms)\n"
  "  tr2= 0.1  (mM)		:gly conc const\n"
  "  :nai0 = 15 (mM)\n"
  "  :nao0 = 140 (mM)\n"
  "  :cai0 = 1.84e-4 (mM)\n"
  "  :cao0 = 1.5 (mM)\n"
  "\n"
  ": Rates\n"
  "\n"
  "  rb1 = 0.257   (/mM /ms)   : binding of glu to C3  			\n"
  "  Ru1 = 0.06  (/ms)	           : unbinding of glu from C3\n"
  "  rb2 = 0.775   (/mM /ms)   : binding of gly to C2\n"
  "  Ru2 = 1.434  (/ms)	           : unbinding  of gly from C2\n"
  "  b   = 3.67 (/ms)	           : opening 		\n"
  "  a   = 0.72   (/ms)	      : closing \n"
  "  Ro2 = 1.62(/ms)		: O1-O2\n"
  "  Ro1 = 0.74(/ms)		: O2-O1\n"
  "  Rd1 = 0.008 (/ms)          : desensitisation C3-D1\n"
  "  Rr1 = 5e-4 (/ms)           : resensitization D1-C3\n"
  "  Rd2 = 0.006 (/ms)          : desensitisation C2-D2\n"
  "  Rr2 = 0.038 (/ms)           : resensitization D2-C2\n"
  "\n"
  ":For Mg\n"
  "Mg=1(mM)	:extracellular Mg conc\n"
  "K0=4.1(mM)	:IC50 at 0 mV\n"
  "delta= 0.8		:electrical distance\n"
  "T= 37 (degC)\n"
  "z=2		:Mg charge\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "  v		(mV)		: postsynaptic voltage\n"
  "  curr		(nA)		\n"
  "  g 		(pS)\n"
  "  C (mM) 				:pointer to pass conc of transmitter \n"
  "  Rb1  (/ms)\n"
  "  Rb2 (/ms)\n"
  "  ica (nA)\n"
  "  ina (nA)\n"
  "  ik (nA)\n"
  "  MB (1)\n"
  "}\n"
  "\n"
  "STATE {		\n"
  "  C3		: unbound, traps glu\n"
  "  C2		: glu bound, traps gly, controls channel opening\n"
  "  C1		: gly bound, channel opens\n"
  "  O1		: Open state 1 \n"
  "  O2		: Open state 2 (kinetically distinct)\n"
  "  D1		: desensitized, from C3\n"
  "  D2       		: desensitized, from C2\n"
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
  "\n"
  "\n"
  "\n"
  "BREAKPOINT {			\n"
  "  SOLVE kstates METHOD sparse\n"
  "  MgBlock(v) \n"
  "  g = gmax * (O1+O2)\n"
  "  curr = (1e-6) *MB* g * (v - Erev)\n"
  "  ica = 0.816*curr\n"
  "  ina = 0.15*curr\n"
  "  ik = 0.06*curr	\n"
  "}\n"
  "\n"
  "\n"
  "KINETIC kstates {			\n"
  "    Rb1 = rb1 * C\n"
  "    Rb2 = rb2 * tr2\n"
  "\n"
  "  ~ C3 <-> C2	(Rb1, Ru1)			\n"
  "  ~ C2 <-> C1	(Rb2, Ru2)\n"
  "  ~ C1 <-> O1	(b, a)\n"
  "  ~ O1 <-> O2	(Ro2, Ro1)\n"
  "  ~ C3 <-> D1	(Rd1, Rr1)\n"
  "  ~ C2 <-> D2    	(Rd2, Rr2)\n"
  " \n"
  "  CONSERVE C3+C2+C1+D1+D2+O1+O2 = 1\n"
  " }\n"
  "\n"
  "FUNCTION MgBlock(v(mV)){ \n"
  "  MB= 1/(1+(Mg/K0)*exp((-z)*delta*F*v/R/(T+273.15)))\n"
  "}\n"
  "\n"
  ;
#endif
