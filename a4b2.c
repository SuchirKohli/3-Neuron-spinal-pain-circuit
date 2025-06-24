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
 
#define nrn_init _nrn_init__a4b2
#define _nrn_initial _nrn_initial__a4b2
#define nrn_cur _nrn_cur__a4b2
#define _nrn_current _nrn_current__a4b2
#define nrn_jacob _nrn_jacob__a4b2
#define nrn_state _nrn_state__a4b2
#define _net_receive _net_receive__a4b2 
#define kstates kstates__a4b2 
 
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
#define rb _p[3]
#define rb_columnindex 3
#define rdb1 _p[4]
#define rdb1_columnindex 4
#define rdb2 _p[5]
#define rdb2_columnindex 5
#define curr _p[6]
#define curr_columnindex 6
#define g _p[7]
#define g_columnindex 7
#define ica _p[8]
#define ica_columnindex 8
#define ina _p[9]
#define ina_columnindex 9
#define C0 _p[10]
#define C0_columnindex 10
#define C1 _p[11]
#define C1_columnindex 11
#define C2 _p[12]
#define C2_columnindex 12
#define O _p[13]
#define O_columnindex 13
#define D0 _p[14]
#define D0_columnindex 14
#define D1 _p[15]
#define D1_columnindex 15
#define D2 _p[16]
#define D2_columnindex 16
#define DC0 _p[17]
#define DC0_columnindex 17
#define DC1 _p[18]
#define DC1_columnindex 18
#define DC2 _p[19]
#define DC2_columnindex 19
#define DO _p[20]
#define DO_columnindex 20
#define DD0 _p[21]
#define DD0_columnindex 21
#define DD1 _p[22]
#define DD1_columnindex 22
#define DD2 _p[23]
#define DD2_columnindex 23
#define _g _p[24]
#define _g_columnindex 24
#define _nd_area  *_ppvar[0]._pval
#define _ion_ina	*_ppvar[2]._pval
#define _ion_dinadv	*_ppvar[3]._pval
#define _ion_ica	*_ppvar[4]._pval
#define _ion_dicadv	*_ppvar[5]._pval
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
#define Erev Erev_a4b2
 double Erev = 0;
#define Rr Rr_a4b2
 double Rr = 1e-05;
#define Rd Rd_a4b2
 double Rd = 0.004;
#define Rdc Rdc_a4b2
 double Rdc = 5e-06;
#define Rrc Rrc_a4b2
 double Rrc = 0.004;
#define Rdu2 Rdu2_a4b2
 double Rdu2 = 0.023;
#define Rdu1 Rdu1_a4b2
 double Rdu1 = 0.046;
#define Rdb2 Rdb2_a4b2
 double Rdb2 = 0;
#define Rdb1 Rdb1_a4b2
 double Rdb1 = 0;
#define Ru Ru_a4b2
 double Ru = 18;
#define Rb Rb_a4b2
 double Rb = 0;
#define a a_a4b2
 double a = 1.2;
#define b b_a4b2
 double b = 50;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "Erev_a4b2", "mV",
 "Ru_a4b2", "/ms",
 "b_a4b2", "/ms",
 "a_a4b2", "/ms",
 "Rd_a4b2", "/ms",
 "Rr_a4b2", "/ms",
 "Rdu1_a4b2", "/ms",
 "Rdu2_a4b2", "/ms",
 "Rrc_a4b2", "/ms",
 "Rdc_a4b2", "/ms",
 "Rb_a4b2", "/ms",
 "Rdb1_a4b2", "/ms",
 "Rdb2_a4b2", "/ms",
 "gmax", "pS",
 "tdur", "ms",
 "del", "ms",
 "rb", "/mM",
 "rdb1", "/mM",
 "rdb2", "/mM",
 "curr", "nA",
 "g", "pS",
 "ica", "nA",
 "ina", "nA",
 "C", "mM",
 0,0
};
 static double C20 = 0;
 static double C10 = 0;
 static double C00 = 0;
 static double D20 = 0;
 static double D10 = 0;
 static double D00 = 0;
 static double O0 = 0;
 static double delta_t = 0.01;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "Erev_a4b2", &Erev_a4b2,
 "Ru_a4b2", &Ru_a4b2,
 "b_a4b2", &b_a4b2,
 "a_a4b2", &a_a4b2,
 "Rd_a4b2", &Rd_a4b2,
 "Rr_a4b2", &Rr_a4b2,
 "Rdu1_a4b2", &Rdu1_a4b2,
 "Rdu2_a4b2", &Rdu2_a4b2,
 "Rrc_a4b2", &Rrc_a4b2,
 "Rdc_a4b2", &Rdc_a4b2,
 "Rb_a4b2", &Rb_a4b2,
 "Rdb1_a4b2", &Rdb1_a4b2,
 "Rdb2_a4b2", &Rdb2_a4b2,
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
"a4b2",
 "gmax",
 "tdur",
 "del",
 "rb",
 "rdb1",
 "rdb2",
 0,
 "curr",
 "g",
 "ica",
 "ina",
 0,
 "C0",
 "C1",
 "C2",
 "O",
 "D0",
 "D1",
 "D2",
 0,
 "C",
 0};
 static Symbol* _na_sym;
 static Symbol* _ca_sym;
 
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
 	gmax = 48;
 	tdur = 5;
 	del = 0;
 	rb = 110;
 	rdb1 = 570;
 	rdb2 = 1100;
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
 prop_ion = need_memb(_ca_sym);
 	_ppvar[4]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[5]._pval = &prop_ion->param[4]; /* _ion_dicadv */
 
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

 void _a4b2_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("na", -10000.);
 	ion_reg("ca", -10000.);
 	_na_sym = hoc_lookup("na_ion");
 	_ca_sym = hoc_lookup("ca_ion");
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
  hoc_register_dparam_semantics(_mechtype, 4, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 6, "pointer");
  hoc_register_dparam_semantics(_mechtype, 7, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 a4b2 a4b2.mod\n");
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
 Rb = rb * C ;
   Rdb1 = rdb1 * C ;
   Rdb2 = rdb2 * C ;
   /* ~ C0 <-> C1 ( 2.0 * Rb , Ru )*/
 f_flux =  2.0 * Rb * C0 ;
 b_flux =  Ru * C1 ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 2) += (f_flux - b_flux);
 
 _term =  2.0 * Rb ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  Ru ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ C1 <-> C2 ( Rb , 2.0 * Ru )*/
 f_flux =  Rb * C1 ;
 b_flux =  2.0 * Ru * C2 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 
 _term =  Rb ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  2.0 * Ru ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ C2 <-> O ( b , a )*/
 f_flux =  b * C2 ;
 b_flux =  a * O ;
 _RHS1( 1) -= (f_flux - b_flux);
 
 _term =  b ;
 _MATELM1( 1 ,1)  += _term;
 _term =  a ;
 _MATELM1( 1 ,0)  -= _term;
 /*REACTION*/
  /* ~ O <-> D0 ( Rd , Rr )*/
 f_flux =  Rd * O ;
 b_flux =  Rr * D0 ;
 _RHS1( 4) += (f_flux - b_flux);
 
 _term =  Rd ;
 _MATELM1( 4 ,0)  -= _term;
 _term =  Rr ;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ D0 <-> D1 ( Rdu1 , Rdb1 )*/
 f_flux =  Rdu1 * D0 ;
 b_flux =  Rdb1 * D1 ;
 _RHS1( 4) -= (f_flux - b_flux);
 _RHS1( 6) += (f_flux - b_flux);
 
 _term =  Rdu1 ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 6 ,4)  -= _term;
 _term =  Rdb1 ;
 _MATELM1( 4 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ D1 <-> D2 ( Rdu2 , Rdb2 )*/
 f_flux =  Rdu2 * D1 ;
 b_flux =  Rdb2 * D2 ;
 _RHS1( 6) -= (f_flux - b_flux);
 _RHS1( 5) += (f_flux - b_flux);
 
 _term =  Rdu2 ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 5 ,6)  -= _term;
 _term =  Rdb2 ;
 _MATELM1( 6 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ D2 <-> C0 ( Rrc , Rdc )*/
 f_flux =  Rrc * D2 ;
 b_flux =  Rdc * C0 ;
 _RHS1( 5) -= (f_flux - b_flux);
 _RHS1( 3) += (f_flux - b_flux);
 
 _term =  Rrc ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 3 ,5)  -= _term;
 _term =  Rdc ;
 _MATELM1( 5 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
   /* C0 + C1 + C2 + D0 + D1 + D2 + O = 1.0 */
 _RHS1(0) =  1.0;
 _MATELM1(0, 0) = 1;
 _RHS1(0) -= O ;
 _MATELM1(0, 5) = 1;
 _RHS1(0) -= D2 ;
 _MATELM1(0, 6) = 1;
 _RHS1(0) -= D1 ;
 _MATELM1(0, 4) = 1;
 _RHS1(0) -= D0 ;
 _MATELM1(0, 1) = 1;
 _RHS1(0) -= C2 ;
 _MATELM1(0, 2) = 1;
 _RHS1(0) -= C1 ;
 _MATELM1(0, 3) = 1;
 _RHS1(0) -= C0 ;
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE ode begin*/
 static int _ode_spec1() {_reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<7;_i++) _p[_dlist1[_i]] = 0.0;}
 Rb = rb * C ;
 Rdb1 = rdb1 * C ;
 Rdb2 = rdb2 * C ;
 /* ~ C0 <-> C1 ( 2.0 * Rb , Ru )*/
 f_flux =  2.0 * Rb * C0 ;
 b_flux =  Ru * C1 ;
 DC0 -= (f_flux - b_flux);
 DC1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C1 <-> C2 ( Rb , 2.0 * Ru )*/
 f_flux =  Rb * C1 ;
 b_flux =  2.0 * Ru * C2 ;
 DC1 -= (f_flux - b_flux);
 DC2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C2 <-> O ( b , a )*/
 f_flux =  b * C2 ;
 b_flux =  a * O ;
 DC2 -= (f_flux - b_flux);
 DO += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ O <-> D0 ( Rd , Rr )*/
 f_flux =  Rd * O ;
 b_flux =  Rr * D0 ;
 DO -= (f_flux - b_flux);
 DD0 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ D0 <-> D1 ( Rdu1 , Rdb1 )*/
 f_flux =  Rdu1 * D0 ;
 b_flux =  Rdb1 * D1 ;
 DD0 -= (f_flux - b_flux);
 DD1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ D1 <-> D2 ( Rdu2 , Rdb2 )*/
 f_flux =  Rdu2 * D1 ;
 b_flux =  Rdb2 * D2 ;
 DD1 -= (f_flux - b_flux);
 DD2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ D2 <-> C0 ( Rrc , Rdc )*/
 f_flux =  Rrc * D2 ;
 b_flux =  Rdc * C0 ;
 DD2 -= (f_flux - b_flux);
 DC0 += (f_flux - b_flux);
 
 /*REACTION*/
   /* C0 + C1 + C2 + D0 + D1 + D2 + O = 1.0 */
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
 Rb = rb * C ;
 Rdb1 = rdb1 * C ;
 Rdb2 = rdb2 * C ;
 /* ~ C0 <-> C1 ( 2.0 * Rb , Ru )*/
 _term =  2.0 * Rb ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  Ru ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ C1 <-> C2 ( Rb , 2.0 * Ru )*/
 _term =  Rb ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  2.0 * Ru ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ C2 <-> O ( b , a )*/
 _term =  b ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 0 ,1)  -= _term;
 _term =  a ;
 _MATELM1( 1 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ O <-> D0 ( Rd , Rr )*/
 _term =  Rd ;
 _MATELM1( 0 ,0)  += _term;
 _MATELM1( 4 ,0)  -= _term;
 _term =  Rr ;
 _MATELM1( 0 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ D0 <-> D1 ( Rdu1 , Rdb1 )*/
 _term =  Rdu1 ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 6 ,4)  -= _term;
 _term =  Rdb1 ;
 _MATELM1( 4 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ D1 <-> D2 ( Rdu2 , Rdb2 )*/
 _term =  Rdu2 ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 5 ,6)  -= _term;
 _term =  Rdb2 ;
 _MATELM1( 6 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ D2 <-> C0 ( Rrc , Rdc )*/
 _term =  Rrc ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 3 ,5)  -= _term;
 _term =  Rdc ;
 _MATELM1( 5 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
   /* C0 + C1 + C2 + D0 + D1 + D2 + O = 1.0 */
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
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  C2 = C20;
  C1 = C10;
  C0 = C00;
  D0 = D00;
  D2 = D20;
  D1 = D10;
  O = O0;
 {
   C0 = 1.0 ;
   C1 = 0.0 ;
   C2 = 0.0 ;
   D0 = 0.0 ;
   D1 = 0.0 ;
   D2 = 0.0 ;
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
   curr = ( 1e-6 ) * g * ( v - Erev ) ;
   ica = 0.6 * curr ;
   ina = 0.4 * curr ;
   }
 _current += ina;
 _current += ica;

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
 	{ double _dica;
 double _dina;
  _dina = ina;
  _dica = ica;
 _rhs = _nrn_current(_v);
  _ion_dinadv += (_dina - ina)/.001 * 1.e2/ (_nd_area);
  _ion_dicadv += (_dica - ica)/.001 * 1.e2/ (_nd_area);
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina * 1.e2/ (_nd_area);
  _ion_ica += ica * 1.e2/ (_nd_area);
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
 if(error){fprintf(stderr,"at line 78 in file a4b2.mod:\n\n"); nrn_complain(_p); abort_run(error);}
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
 _slist1[1] = C2_columnindex;  _dlist1[1] = DC2_columnindex;
 _slist1[2] = C1_columnindex;  _dlist1[2] = DC1_columnindex;
 _slist1[3] = C0_columnindex;  _dlist1[3] = DC0_columnindex;
 _slist1[4] = D0_columnindex;  _dlist1[4] = DD0_columnindex;
 _slist1[5] = D2_columnindex;  _dlist1[5] = DD2_columnindex;
 _slist1[6] = D1_columnindex;  _dlist1[6] = DD1_columnindex;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "a4b2.mod";
static const char* nmodl_file_text = 
  "NEURON {\n"
  "  POINT_PROCESS a4b2\n"
  "  USEION na WRITE ina\n"
  "  USEION ca WRITE ica\n"
  "  POINTER C\n"
  "  RANGE C0, C1, C2, D1, D2, O, D0, curr, ica, ina\n"
  "  RANGE g, gmax, rb, rdb1, rdb2, del, tdur\n"
  "  GLOBAL Erev\n"
  "  GLOBAL Rb, Ru, Rdb1, Rdb2, Rdu1, Rdu2, a, b, Rrc, Rdc \n"
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
  "}\n"
  "\n"
  "PARAMETER {\n"
  "  Erev	= 0    (mV)	: reversal potential\n"
  "  gmax	= 48  (pS)	: maximal conductance\n"
  "  tdur	= 5 (ms)\n"
  "  del 	= 0 (ms)\n"
  "\n"
  ": Rates\n"
  "\n"
  "  rb = 1.1e2   (/mM /ms)   : binding  			\n"
  "  Ru = 18  (/ms)	           : unbinding\n"
  "  b = 50 (/ms)	           : opening 		\n"
  "  a = 1.2   (/ms)	      : closing \n"
  "  Rd = 0.004 (/ms)          : desensitization \n"
  "  Rr = 1e-5 (/ms)           : resensitization\n"
  "  Rdu1 = 0.046(/ms)	       : unbinding from 1st desensitization state\n"
  "  rdb1 = 5.7e2    (/mM /ms)	: binding to 1st desensitization state\n"
  "  Rdu2 = 0.023   (/ms)	  : unbinding from 2nd desensitization state\n"
  "  rdb2 = 1.1e3 (/mM /ms)    : binding to 2nd desensitization state\n"
  "  Rrc = 0.004 (/ms)          : resensitization to closed state\n"
  "  Rdc = 5e-6 (/ms)           : desensitization from closed state\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "  v		(mV)		: postsynaptic voltage\n"
  "  curr	(nA)			: current = g*(v - Erev)\n"
  "  g 		(pS)		: conductance\n"
  "  C (mM)\n"
  "  Rb		(/ms)    \n"
  "  Rdb1  (/ms)\n"
  "  Rdb2 (/ms)\n"
  "  ica (nA)\n"
  "  ina (nA)\n"
  "}\n"
  "\n"
  "STATE {\n"
  "  C0		: unbound\n"
  "  C1		: single ACh bound\n"
  "  C2		: double ACh bound\n"
  "  O		: Open state \n"
  "  D0		: double ACh bound, desensitized\n"
  "  D1       		: single ACh bound, desensitized\n"
  "  D2 		: unbound, desensitized\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "  C0 = 1\n"
  "  C1 = 0\n"
  "  C2 = 0\n"
  "  D0 = 0\n"
  "  D1 = 0\n"
  "  D2 = 0\n"
  "  O = 0\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "  SOLVE kstates METHOD sparse\n"
  "\n"
  "  g = gmax * O\n"
  "  curr = (1e-6) * g * (v - Erev)\n"
  "  ica = 0.6*curr\n"
  "  ina = 0.4*curr\n"
  "}\n"
  "\n"
  "KINETIC kstates {\n"
  "    Rb = rb * C\n"
  "    Rdb1 = rdb1 * C\n"
  "    Rdb2 = rdb2 * C\n"
  "\n"
  "  ~ C0  <-> C1	(2*Rb, Ru)\n"
  "  ~ C1 <-> C2	(Rb, 2*Ru)\n"
  "  ~ C2 <-> O	(b, a)\n"
  "  ~ O <-> D0	(Rd, Rr)\n"
  "  ~ D0 <-> D1	(Rdu1, Rdb1)\n"
  "  ~ D1 <-> D2    (Rdu2, Rdb2)\n"
  "  ~ D2 <-> C0    (Rrc, Rdc)\n"
  " \n"
  "  CONSERVE C0+C1+C2+D0+D1+D2+O = 1\n"
  " }\n"
  ;
#endif
