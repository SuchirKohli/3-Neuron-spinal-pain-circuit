/* Created by Language version: 7.7.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
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
 
#define nrn_init _nrn_init__NaV16
#define _nrn_initial _nrn_initial__NaV16
#define nrn_cur _nrn_cur__NaV16
#define _nrn_current _nrn_current__NaV16
#define nrn_jacob _nrn_jacob__NaV16
#define nrn_state _nrn_state__NaV16
#define _net_receive _net_receive__NaV16 
#define kstates kstates__NaV16 
#define rates rates__NaV16 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define ina _p[0]
#define ina_columnindex 0
#define g _p[1]
#define g_columnindex 1
#define C1 _p[2]
#define C1_columnindex 2
#define C2 _p[3]
#define C2_columnindex 3
#define O1 _p[4]
#define O1_columnindex 4
#define O2 _p[5]
#define O2_columnindex 5
#define I1 _p[6]
#define I1_columnindex 6
#define I2 _p[7]
#define I2_columnindex 7
#define ena _p[8]
#define ena_columnindex 8
#define nai _p[9]
#define nai_columnindex 9
#define nao _p[10]
#define nao_columnindex 10
#define RC1C2 _p[11]
#define RC1C2_columnindex 11
#define RC2C1 _p[12]
#define RC2C1_columnindex 12
#define RC2O1 _p[13]
#define RC2O1_columnindex 13
#define RO1C2 _p[14]
#define RO1C2_columnindex 14
#define RC2O2 _p[15]
#define RC2O2_columnindex 15
#define RO2C2 _p[16]
#define RO2C2_columnindex 16
#define RO1I1 _p[17]
#define RO1I1_columnindex 17
#define RI1O1 _p[18]
#define RI1O1_columnindex 18
#define RI1I2 _p[19]
#define RI1I2_columnindex 19
#define RI2I1 _p[20]
#define RI2I1_columnindex 20
#define RI1C1 _p[21]
#define RI1C1_columnindex 21
#define RC1I1 _p[22]
#define RC1I1_columnindex 22
#define Q10 _p[23]
#define Q10_columnindex 23
#define DC1 _p[24]
#define DC1_columnindex 24
#define DC2 _p[25]
#define DC2_columnindex 25
#define DO1 _p[26]
#define DO1_columnindex 26
#define DO2 _p[27]
#define DO2_columnindex 27
#define DI1 _p[28]
#define DI1_columnindex 28
#define DI2 _p[29]
#define DI2_columnindex 29
#define v _p[30]
#define v_columnindex 30
#define _g _p[31]
#define _g_columnindex 31
#define _ion_ena	*_ppvar[0]._pval
#define _ion_ina	*_ppvar[1]._pval
#define _ion_dinadv	*_ppvar[2]._pval
 
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
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_rates2(void);
 static void _hoc_rates(void);
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

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_NaV16", _hoc_setdata,
 "rates2_NaV16", _hoc_rates2,
 "rates_NaV16", _hoc_rates,
 0, 0
};
#define rates2 rates2_NaV16
 extern double rates2( _threadargsprotocomma_ double , double , double , double );
 /* declare global and static user variables */
#define C1I1k2 C1I1k2_NaV16
 double C1I1k2 = -12;
#define C1I1v2 C1I1v2_NaV16
 double C1I1v2 = -55;
#define C1I1b2 C1I1b2_NaV16
 double C1I1b2 = 0.08;
#define C2O2k2 C2O2k2_NaV16
 double C2O2k2 = -8;
#define C2O2v2 C2O2v2_NaV16
 double C2O2v2 = -10;
#define C2O2b2 C2O2b2_NaV16
 double C2O2b2 = 0.0001;
#define C2O1k2 C2O1k2_NaV16
 double C2O1k2 = -10;
#define C2O1v2 C2O1v2_NaV16
 double C2O1v2 = -18;
#define C2O1b2 C2O1b2_NaV16
 double C2O1b2 = 14;
#define C2C1k2 C2C1k2_NaV16
 double C2C1k2 = -10;
#define C2C1v2 C2C1v2_NaV16
 double C2C1v2 = -8;
#define C2C1b2 C2C1b2_NaV16
 double C2C1b2 = 14;
#define C2C1k1 C2C1k1_NaV16
 double C2C1k1 = 9;
#define C2C1v1 C2C1v1_NaV16
 double C2C1v1 = -38;
#define C2C1b1 C2C1b1_NaV16
 double C2C1b1 = 2;
#define C1C2k2 C1C2k2_NaV16
 double C1C2k2 = -10;
#define C1C2v2 C1C2v2_NaV16
 double C1C2v2 = -8;
#define C1C2b2 C1C2b2_NaV16
 double C1C2b2 = 14;
#define I2I1k1 I2I1k1_NaV16
 double I2I1k1 = 30;
#define I2I1v1 I2I1v1_NaV16
 double I2I1v1 = -90;
#define I2I1b1 I2I1b1_NaV16
 double I2I1b1 = 0.0018;
#define I1I2k2 I1I2k2_NaV16
 double I1I2k2 = -5;
#define I1I2v2 I1I2v2_NaV16
 double I1I2v2 = -50;
#define I1I2b2 I1I2b2_NaV16
 double I1I2b2 = 0.00022;
#define I1C1k1 I1C1k1_NaV16
 double I1C1k1 = 9;
#define I1C1v1 I1C1v1_NaV16
 double I1C1v1 = -86;
#define I1C1b1 I1C1b1_NaV16
 double I1C1b1 = 0.1;
#define I1O1k1 I1O1k1_NaV16
 double I1O1k1 = 10;
#define I1O1v1 I1O1v1_NaV16
 double I1O1v1 = -40;
#define I1O1b1 I1O1b1_NaV16
 double I1O1b1 = 1e-05;
#define O1I1k2 O1I1k2_NaV16
 double O1I1k2 = -18;
#define O1I1v2 O1I1v2_NaV16
 double O1I1v2 = 15;
#define O1I1b2 O1I1b2_NaV16
 double O1I1b2 = 10;
#define O1I1k1 O1I1k1_NaV16
 double O1I1k1 = 13;
#define O1I1v1 O1I1v1_NaV16
 double O1I1v1 = -40;
#define O1I1b1 O1I1b1_NaV16
 double O1I1b1 = 6;
#define O2C2k2 O2C2k2_NaV16
 double O2C2k2 = -5;
#define O2C2v2 O2C2v2_NaV16
 double O2C2v2 = -20;
#define O2C2b2 O2C2b2_NaV16
 double O2C2b2 = 0.0001;
#define O2C2k1 O2C2k1_NaV16
 double O2C2k1 = 10;
#define O2C2v1 O2C2v1_NaV16
 double O2C2v1 = -55;
#define O2C2b1 O2C2b1_NaV16
 double O2C2b1 = 0.0001;
#define O1C2k2 O1C2k2_NaV16
 double O1C2k2 = -10;
#define O1C2v2 O1C2v2_NaV16
 double O1C2v2 = -18;
#define O1C2b2 O1C2b2_NaV16
 double O1C2b2 = 14;
#define O1C2k1 O1C2k1_NaV16
 double O1C2k1 = 9;
#define O1C2v1 O1C2v1_NaV16
 double O1C2v1 = -48;
#define O1C2b1 O1C2b1_NaV16
 double O1C2b1 = 4;
#define gbar gbar_NaV16
 double gbar = 0.12;
#define nao0 nao0_NaV16
 double nao0 = 140;
#define nai0 nai0_NaV16
 double nai0 = 15;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "nai0_NaV16", "mM",
 "nao0_NaV16", "mM",
 "gbar_NaV16", "S/cm2",
 "ina_NaV16", "mA/cm2",
 "g_NaV16", "mho/cm2",
 0,0
};
 static double C20 = 0;
 static double C10 = 0;
 static double I20 = 0;
 static double I10 = 0;
 static double O20 = 0;
 static double O10 = 0;
 static double delta_t = 0.01;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "nai0_NaV16", &nai0_NaV16,
 "nao0_NaV16", &nao0_NaV16,
 "gbar_NaV16", &gbar_NaV16,
 "C1C2b2_NaV16", &C1C2b2_NaV16,
 "C1C2v2_NaV16", &C1C2v2_NaV16,
 "C1C2k2_NaV16", &C1C2k2_NaV16,
 "C2C1b1_NaV16", &C2C1b1_NaV16,
 "C2C1v1_NaV16", &C2C1v1_NaV16,
 "C2C1k1_NaV16", &C2C1k1_NaV16,
 "C2C1b2_NaV16", &C2C1b2_NaV16,
 "C2C1v2_NaV16", &C2C1v2_NaV16,
 "C2C1k2_NaV16", &C2C1k2_NaV16,
 "C2O1b2_NaV16", &C2O1b2_NaV16,
 "C2O1v2_NaV16", &C2O1v2_NaV16,
 "C2O1k2_NaV16", &C2O1k2_NaV16,
 "O1C2b1_NaV16", &O1C2b1_NaV16,
 "O1C2v1_NaV16", &O1C2v1_NaV16,
 "O1C2k1_NaV16", &O1C2k1_NaV16,
 "O1C2b2_NaV16", &O1C2b2_NaV16,
 "O1C2v2_NaV16", &O1C2v2_NaV16,
 "O1C2k2_NaV16", &O1C2k2_NaV16,
 "C2O2b2_NaV16", &C2O2b2_NaV16,
 "C2O2v2_NaV16", &C2O2v2_NaV16,
 "C2O2k2_NaV16", &C2O2k2_NaV16,
 "O2C2b1_NaV16", &O2C2b1_NaV16,
 "O2C2v1_NaV16", &O2C2v1_NaV16,
 "O2C2k1_NaV16", &O2C2k1_NaV16,
 "O2C2b2_NaV16", &O2C2b2_NaV16,
 "O2C2v2_NaV16", &O2C2v2_NaV16,
 "O2C2k2_NaV16", &O2C2k2_NaV16,
 "O1I1b1_NaV16", &O1I1b1_NaV16,
 "O1I1v1_NaV16", &O1I1v1_NaV16,
 "O1I1k1_NaV16", &O1I1k1_NaV16,
 "O1I1b2_NaV16", &O1I1b2_NaV16,
 "O1I1v2_NaV16", &O1I1v2_NaV16,
 "O1I1k2_NaV16", &O1I1k2_NaV16,
 "I1O1b1_NaV16", &I1O1b1_NaV16,
 "I1O1v1_NaV16", &I1O1v1_NaV16,
 "I1O1k1_NaV16", &I1O1k1_NaV16,
 "I1C1b1_NaV16", &I1C1b1_NaV16,
 "I1C1v1_NaV16", &I1C1v1_NaV16,
 "I1C1k1_NaV16", &I1C1k1_NaV16,
 "C1I1b2_NaV16", &C1I1b2_NaV16,
 "C1I1v2_NaV16", &C1I1v2_NaV16,
 "C1I1k2_NaV16", &C1I1k2_NaV16,
 "I1I2b2_NaV16", &I1I2b2_NaV16,
 "I1I2v2_NaV16", &I1I2v2_NaV16,
 "I1I2k2_NaV16", &I1I2k2_NaV16,
 "I2I1b1_NaV16", &I2I1b1_NaV16,
 "I2I1v1_NaV16", &I2I1v1_NaV16,
 "I2I1k1_NaV16", &I2I1k1_NaV16,
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
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(NrnThread*, _Memb_list*, int);
static void _ode_matsol(NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[3]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"NaV16",
 0,
 "ina_NaV16",
 "g_NaV16",
 0,
 "C1_NaV16",
 "C2_NaV16",
 "O1_NaV16",
 "O2_NaV16",
 "I1_NaV16",
 "I2_NaV16",
 0,
 0};
 static Symbol* _na_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 32, _prop);
 	/*initialize range parameters*/
 	_prop->param = _p;
 	_prop->param_size = 32;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ena */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _thread_cleanup(Datum*);
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _NaV16_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("na", -10000.);
 	_na_sym = hoc_lookup("na_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 3);
  _extcall_thread = (Datum*)ecalloc(2, sizeof(Datum));
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 0, _thread_cleanup);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 32, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 NaV16 NaV16.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates(_threadargsprotocomma_ double);
 extern double *_nrn_thread_getelm(SparseObj*, int, int);
 
#define _MATELM1(_row,_col) *(_nrn_thread_getelm(_so, _row + 1, _col + 1))
 
#define _RHS1(_arg) _rhs[_arg+1]
  
#define _linmat1  1
 static int _spth1 = 1;
 static int _cvspth1 = 0;
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[6], _dlist1[6]; static double *_temp1;
 static int kstates();
 
static int kstates (void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt)
 {int _reset=0;
 {
   double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=1;_i<6;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 rates ( _threadargscomma_ v ) ;
   /* ~ C1 <-> C2 ( RC1C2 , RC2C1 )*/
 f_flux =  RC1C2 * C1 ;
 b_flux =  RC2C1 * C2 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 
 _term =  RC1C2 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  RC2C1 ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ C2 <-> O1 ( RC2O1 , RO1C2 )*/
 f_flux =  RC2O1 * C2 ;
 b_flux =  RO1C2 * O1 ;
 _RHS1( 1) -= (f_flux - b_flux);
 _RHS1( 5) += (f_flux - b_flux);
 
 _term =  RC2O1 ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 5 ,1)  -= _term;
 _term =  RO1C2 ;
 _MATELM1( 1 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ C2 <-> O2 ( RC2O2 , RO2C2 )*/
 f_flux =  RC2O2 * C2 ;
 b_flux =  RO2C2 * O2 ;
 _RHS1( 1) -= (f_flux - b_flux);
 _RHS1( 4) += (f_flux - b_flux);
 
 _term =  RC2O2 ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 4 ,1)  -= _term;
 _term =  RO2C2 ;
 _MATELM1( 1 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ O1 <-> I1 ( RO1I1 , RI1O1 )*/
 f_flux =  RO1I1 * O1 ;
 b_flux =  RI1O1 * I1 ;
 _RHS1( 5) -= (f_flux - b_flux);
 _RHS1( 3) += (f_flux - b_flux);
 
 _term =  RO1I1 ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 3 ,5)  -= _term;
 _term =  RI1O1 ;
 _MATELM1( 5 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ I1 <-> C1 ( RI1C1 , RC1I1 )*/
 f_flux =  RI1C1 * I1 ;
 b_flux =  RC1I1 * C1 ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 2) += (f_flux - b_flux);
 
 _term =  RI1C1 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  RC1I1 ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ I1 <-> I2 ( RI1I2 , RI2I1 )*/
 f_flux =  RI1I2 * I1 ;
 b_flux =  RI2I1 * I2 ;
 _RHS1( 3) -= (f_flux - b_flux);
 
 _term =  RI1I2 ;
 _MATELM1( 3 ,3)  += _term;
 _term =  RI2I1 ;
 _MATELM1( 3 ,0)  -= _term;
 /*REACTION*/
   /* O1 + O2 + C1 + C2 + I1 + I2 = 1.0 */
 _RHS1(0) =  1.0;
 _MATELM1(0, 0) = 1;
 _RHS1(0) -= I2 ;
 _MATELM1(0, 3) = 1;
 _RHS1(0) -= I1 ;
 _MATELM1(0, 1) = 1;
 _RHS1(0) -= C2 ;
 _MATELM1(0, 2) = 1;
 _RHS1(0) -= C1 ;
 _MATELM1(0, 4) = 1;
 _RHS1(0) -= O2 ;
 _MATELM1(0, 5) = 1;
 _RHS1(0) -= O1 ;
 /*CONSERVATION*/
   } return _reset;
 }
 
double rates2 ( _threadargsprotocomma_ double _lv , double _lb , double _lvv , double _lk ) {
   double _lrates2;
 _lrates2 = ( _lb / ( 1.0 + exp ( ( _lv - _lvv ) / _lk ) ) ) ;
   
return _lrates2;
 }
 
static void _hoc_rates2(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  rates2 ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) , *getarg(3) , *getarg(4) );
 hoc_retpushx(_r);
}
 
static int  rates ( _threadargsprotocomma_ double _lv ) {
    RC1C2 = Q10 * ( rates2 ( _threadargscomma_ _lv , C1C2b2 , C1C2v2 , C1C2k2 ) ) ;
   RC2C1 = Q10 * ( rates2 ( _threadargscomma_ _lv , C2C1b1 , C2C1v1 , C2C1k1 ) + rates2 ( _threadargscomma_ _lv , C2C1b2 , C2C1v2 , C2C1k2 ) ) ;
   RC2O1 = Q10 * ( rates2 ( _threadargscomma_ _lv , C2O1b2 , C2O1v2 , C2O1k2 ) ) ;
   RO1C2 = Q10 * ( rates2 ( _threadargscomma_ _lv , O1C2b1 , O1C2v1 , O1C2k1 ) + rates2 ( _threadargscomma_ _lv , O1C2b2 , O1C2v2 , O1C2k2 ) ) ;
   RC2O2 = Q10 * ( rates2 ( _threadargscomma_ _lv , C2O2b2 , C2O2v2 , C2O2k2 ) ) ;
   RO2C2 = Q10 * ( rates2 ( _threadargscomma_ _lv , O2C2b1 , O2C2v1 , O2C2k1 ) + rates2 ( _threadargscomma_ _lv , O2C2b2 , O2C2v2 , O2C2k2 ) ) ;
   RO1I1 = Q10 * ( rates2 ( _threadargscomma_ _lv , O1I1b1 , O1I1v1 , O1I1k1 ) + rates2 ( _threadargscomma_ _lv , O1I1b2 , O1I1v2 , O1I1k2 ) ) ;
   RI1O1 = Q10 * ( rates2 ( _threadargscomma_ _lv , I1O1b1 , I1O1v1 , I1O1k1 ) ) ;
   RI1C1 = Q10 * ( rates2 ( _threadargscomma_ _lv , I1C1b1 , I1C1v1 , I1C1k1 ) ) ;
   RC1I1 = Q10 * ( rates2 ( _threadargscomma_ _lv , C1I1b2 , C1I1v2 , C1I1k2 ) ) ;
   RI1I2 = Q10 * ( rates2 ( _threadargscomma_ _lv , I1I2b2 , I1I2v2 , I1I2k2 ) ) ;
   RI2I1 = Q10 * ( rates2 ( _threadargscomma_ _lv , I2I1b1 , I2I1v1 , I2I1k1 ) ) ;
     return 0; }
 
static void _hoc_rates(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 rates ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
/*CVODE ode begin*/
 static int _ode_spec1(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<6;_i++) _p[_dlist1[_i]] = 0.0;}
 rates ( _threadargscomma_ v ) ;
 /* ~ C1 <-> C2 ( RC1C2 , RC2C1 )*/
 f_flux =  RC1C2 * C1 ;
 b_flux =  RC2C1 * C2 ;
 DC1 -= (f_flux - b_flux);
 DC2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C2 <-> O1 ( RC2O1 , RO1C2 )*/
 f_flux =  RC2O1 * C2 ;
 b_flux =  RO1C2 * O1 ;
 DC2 -= (f_flux - b_flux);
 DO1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C2 <-> O2 ( RC2O2 , RO2C2 )*/
 f_flux =  RC2O2 * C2 ;
 b_flux =  RO2C2 * O2 ;
 DC2 -= (f_flux - b_flux);
 DO2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ O1 <-> I1 ( RO1I1 , RI1O1 )*/
 f_flux =  RO1I1 * O1 ;
 b_flux =  RI1O1 * I1 ;
 DO1 -= (f_flux - b_flux);
 DI1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ I1 <-> C1 ( RI1C1 , RC1I1 )*/
 f_flux =  RI1C1 * I1 ;
 b_flux =  RC1I1 * C1 ;
 DI1 -= (f_flux - b_flux);
 DC1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ I1 <-> I2 ( RI1I2 , RI2I1 )*/
 f_flux =  RI1I2 * I1 ;
 b_flux =  RI2I1 * I2 ;
 DI1 -= (f_flux - b_flux);
 DI2 += (f_flux - b_flux);
 
 /*REACTION*/
   /* O1 + O2 + C1 + C2 + I1 + I2 = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1(void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<6;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 rates ( _threadargscomma_ v ) ;
 /* ~ C1 <-> C2 ( RC1C2 , RC2C1 )*/
 _term =  RC1C2 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  RC2C1 ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ C2 <-> O1 ( RC2O1 , RO1C2 )*/
 _term =  RC2O1 ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 5 ,1)  -= _term;
 _term =  RO1C2 ;
 _MATELM1( 1 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ C2 <-> O2 ( RC2O2 , RO2C2 )*/
 _term =  RC2O2 ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 4 ,1)  -= _term;
 _term =  RO2C2 ;
 _MATELM1( 1 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ O1 <-> I1 ( RO1I1 , RI1O1 )*/
 _term =  RO1I1 ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 3 ,5)  -= _term;
 _term =  RI1O1 ;
 _MATELM1( 5 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ I1 <-> C1 ( RI1C1 , RC1I1 )*/
 _term =  RI1C1 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  RC1I1 ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ I1 <-> I2 ( RI1I2 , RI2I1 )*/
 _term =  RI1I2 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 0 ,3)  -= _term;
 _term =  RI2I1 ;
 _MATELM1( 3 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
   /* O1 + O2 + C1 + C2 + I1 + I2 = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 6;}
 
static void _ode_spec(NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ena = _ion_ena;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 6; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _cvode_sparse_thread(&_thread[_cvspth1]._pvoid, 6, _dlist1, _p, _ode_matsol1, _ppvar, _thread, _nt);
 }
 
static void _ode_matsol(NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ena = _ion_ena;
 _ode_matsol_instance1(_threadargs_);
 }}
 
static void _thread_cleanup(Datum* _thread) {
   _nrn_destroy_sparseobj_thread(_thread[_cvspth1]._pvoid);
   _nrn_destroy_sparseobj_thread(_thread[_spth1]._pvoid);
 }
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_na_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_na_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_na_sym, _ppvar, 2, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {
  int _i; double _save;{
  C2 = C20;
  C1 = C10;
  I2 = I20;
  I1 = I10;
  O2 = O20;
  O1 = O10;
 {
   Q10 = pow( 3.0 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   C1 = 1.0 ;
   C2 = 0.0 ;
   O1 = 0.0 ;
   O2 = 0.0 ;
   I1 = 0.0 ;
   I2 = 0.0 ;
   nai = nai0 ;
   nao = nao0 ;
   }
 
}
}

static void nrn_init(NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
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
  ena = _ion_ena;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   g = gbar * ( O1 + O2 ) ;
   ina = g * ( v - ena ) ;
   }
 _current += ina;

} return _current;
}

static void nrn_cur(NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
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
  ena = _ion_ena;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dina;
  _dina = ina;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dinadv += (_dina - ina)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}
 
}

static void nrn_jacob(NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
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
 
}
 
}

static void nrn_state(NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
double _dtsav = dt;
if (secondorder) { dt *= 0.5; }
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
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
  ena = _ion_ena;
 {  sparse_thread(&_thread[_spth1]._pvoid, 6, _slist1, _dlist1, _p, &t, dt, kstates, _linmat1, _ppvar, _thread, _nt);
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 6; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 } }}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = I2_columnindex;  _dlist1[0] = DI2_columnindex;
 _slist1[1] = C2_columnindex;  _dlist1[1] = DC2_columnindex;
 _slist1[2] = C1_columnindex;  _dlist1[2] = DC1_columnindex;
 _slist1[3] = I1_columnindex;  _dlist1[3] = DI1_columnindex;
 _slist1[4] = O2_columnindex;  _dlist1[4] = DO2_columnindex;
 _slist1[5] = O1_columnindex;  _dlist1[5] = DO1_columnindex;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "NaV16.mod";
static const char* nmodl_file_text = 
  "NEURON {\n"
  "	SUFFIX NaV16 	:modeldb model used suffix, why?\n"
  "	USEION na READ ena WRITE ina\n"
  "	RANGE gmax, ina, g\n"
  "	RANGE C1, C2, O1, O2, I1, I2\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(mA) = (milliamp)\n"
  "	(mV) = (millivolt)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	v (mV)\n"
  "	nai0 = 15 (mM)\n"
  "	nao0 = 140 (mM)\n"
  "	celsius = 37 (degC)\n"
  "	gbar  = 0.12 (S/cm2) \n"
  "	\n"
  "	C1C2b2	  = 14\n"
  "	C1C2v2    = -8\n"
  "	C1C2k2	  = -10\n"
  "	\n"
  "	C2C1b1	  = 2\n"
  "	C2C1v1    = -38\n"
  "	C2C1k1	  = 9\n"
  "	C2C1b2	  = 14\n"
  "	C2C1v2    = -8\n"
  "	C2C1k2	  = -10\n"
  "\n"
  "	C2O1b2	  = 14\n"
  "	C2O1v2    = -18\n"
  "	C2O1k2	  = -10\n"
  "	\n"
  "	O1C2b1	  = 4\n"
  "	O1C2v1    = -48\n"
  "	O1C2k1	  = 9\n"
  "	O1C2b2	  = 14\n"
  "	O1C2v2    = -18\n"
  "	O1C2k2	  = -10\n"
  "	\n"
  "	C2O2b2	  = 1e-4\n"
  "	C2O2v2	  = -10\n"
  "	C2O2k2	  = -8 \n"
  "	\n"
  "	O2C2b1	  = 1e-4\n"
  "	O2C2v1	  = -55\n"
  "	O2C2k1	  = 10\n"
  "	O2C2b2	  = 1e-4\n"
  "	O2C2v2	  = -20\n"
  "	O2C2k2	  = -5\n"
  "	\n"
  "	O1I1b1	  = 6\n"
  "	O1I1v1	  = -40\n"
  "	O1I1k1	  = 13\n"
  "	O1I1b2	  = 10\n"
  "	O1I1v2	  = 15\n"
  "	O1I1k2	  = -18\n"
  "	\n"
  "	I1O1b1	  = 1e-5\n"
  "	I1O1v1	  = -40\n"
  "	I1O1k1	  = 10\n"
  "	\n"
  "	I1C1b1	  = 0.1\n"
  "	I1C1v1	  = -86\n"
  "	I1C1k1	  = 9\n"
  "	\n"
  "	C1I1b2	  = 0.08\n"
  "	C1I1v2	  = -55\n"
  "	C1I1k2	  = -12\n"
  "	\n"
  "	I1I2b2	  = 0.00022\n"
  "	I1I2v2	  = -50\n"
  "	I1I2k2	  = -5\n"
  "\n"
  "	I2I1b1	  = 0.0018\n"
  "	I2I1v1	  = -90\n"
  "	I2I1k1	  = 30\n"
  "	\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	ena (mV)\n"
  "	ina  (mA/cm2)\n"
  "	g   (mho/cm2)\n"
  "	nai (mM)\n"
  "	nao (mM)\n"
  "	RC1C2 (/ms)\n"
  "	RC2C1 (/ms)\n"
  "	RC2O1 (/ms)\n"
  "	RO1C2 (/ms)\n"
  "	RC2O2 (/ms)\n"
  "	RO2C2 (/ms)\n"
  "	RO1I1 (/ms)\n"
  "	RI1O1 (/ms)\n"
  "	RI1I2 (/ms)\n"
  "	RI2I1 (/ms)\n"
  "	RI1C1 (/ms)\n"
  "	RC1I1 (/ms)\n"
  "	Q10 (1)\n"
  "}\n"
  "\n"
  "STATE {\n"
  "	C1\n"
  "	C2\n"
  "	O1\n"
  "	O2\n"
  "	I1\n"
  "	I2\n"
  "}\n"
  "\n"
  "\n"
  "INITIAL {\n"
  "	Q10 = 3^((celsius-20(degC))/10 (degC))\n"
  "	:SOLVE kin\n"
  "	: STEADYSTATE sparse ???\n"
  "	C1=1\n"
  "	C2=0\n"
  "	O1=0\n"
  "	O2=0\n"
  "	I1=0\n"
  "	I2=0\n"
  "	nai=nai0\n"
  "	nao=nao0\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE kstates METHOD sparse\n"
  "	g = gbar * (O1 + O2)	\n"
  "	ina = g * (v - ena)   	\n"
  "}\n"
  "\n"
  "KINETIC kstates {\n"
  "	rates(v)\n"
  "	\n"
  "	~ C1 <->  C2 	(RC1C2, RC2C1)\n"
  "	~ C2 <->  O1 	(RC2O1, RO1C2)\n"
  "	~ C2 <->  O2 	(RC2O2, RO2C2)\n"
  "	~ O1 <->  I1 	(RO1I1, RI1O1)\n"
  "	~ I1   <->  C1 	(RI1C1, RC1I1)\n"
  "	~ I1   <->  I2 	(RI1I2, RI2I1)\n"
  "	\n"
  "	CONSERVE O1 + O2 + C1 + C2 + I1 + I2 = 1\n"
  "}\n"
  "\n"
  "FUNCTION rates2(v, b, vv, k) {\n"
  "	rates2 = (b/(1+exp((v-vv)/k)))\n"
  "}\n"
  "\n"
  "PROCEDURE rates(v(mV)) {\n"
  "UNITSOFF\n"
  "	RC1C2 = Q10*(rates2(v, C1C2b2, C1C2v2, C1C2k2))\n"
  "	RC2C1 = Q10*(rates2(v, C2C1b1, C2C1v1, C2C1k1) + rates2(v, C2C1b2, C2C1v2, C2C1k2))\n"
  "	RC2O1 = Q10*(rates2(v, C2O1b2, C2O1v2, C2O1k2))\n"
  "	RO1C2 = Q10*(rates2(v, O1C2b1, O1C2v1, O1C2k1) + rates2(v, O1C2b2, O1C2v2, O1C2k2))\n"
  "	RC2O2 = Q10*(rates2(v, C2O2b2, C2O2v2, C2O2k2))\n"
  "	RO2C2 = Q10*(rates2(v, O2C2b1, O2C2v1, O2C2k1) + rates2(v, O2C2b2, O2C2v2, O2C2k2))\n"
  "	RO1I1 = Q10*(rates2(v, O1I1b1, O1I1v1, O1I1k1) + rates2(v, O1I1b2, O1I1v2, O1I1k2))\n"
  "	RI1O1 = Q10*(rates2(v, I1O1b1, I1O1v1, I1O1k1))\n"
  "	RI1C1 = Q10*(rates2(v, I1C1b1, I1C1v1, I1C1k1))\n"
  "	RC1I1 = Q10*(rates2(v, C1I1b2, C1I1v2, C1I1k2))\n"
  "	RI1I2 = Q10*(rates2(v, I1I2b2, I1I2v2, I1I2k2))\n"
  "	RI2I1 = Q10*(rates2(v, I2I1b1, I2I1v1, I2I1k1))\n"
  "UNITSON\n"
  "}\n"
  ;
#endif
