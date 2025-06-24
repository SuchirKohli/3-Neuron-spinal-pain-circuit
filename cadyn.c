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
 static void _difusfunc(ldifusfunc2_t, NrnThread*);
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__cdp
#define _nrn_initial _nrn_initial__cdp
#define nrn_cur _nrn_cur__cdp
#define _nrn_current _nrn_current__cdp
#define nrn_jacob _nrn_jacob__cdp
#define nrn_state _nrn_state__cdp
#define _net_receive _net_receive__cdp 
#define factors factors__cdp 
#define state state__cdp 
 
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
#define cai0 _p[0]
#define cai0_columnindex 0
#define cao0 _p[1]
#define cao0_columnindex 1
#define ica_pmp _p[2]
#define ica_pmp_columnindex 2
#define ca (_p + 3)
#define ca_columnindex 3
#define CaBuffer (_p + 6)
#define CaBuffer_columnindex 6
#define Buffer (_p + 9)
#define Buffer_columnindex 9
#define pump _p[12]
#define pump_columnindex 12
#define pumpca _p[13]
#define pumpca_columnindex 13
#define ica _p[14]
#define ica_columnindex 14
#define cai _p[15]
#define cai_columnindex 15
#define cao _p[16]
#define cao_columnindex 16
#define ica_pmp_last _p[17]
#define ica_pmp_last_columnindex 17
#define parea _p[18]
#define parea_columnindex 18
#define Kd _p[19]
#define Kd_columnindex 19
#define B0 _p[20]
#define B0_columnindex 20
#define Dca (_p + 21)
#define Dca_columnindex 21
#define DCaBuffer (_p + 24)
#define DCaBuffer_columnindex 24
#define DBuffer (_p + 27)
#define DBuffer_columnindex 27
#define Dpump _p[30]
#define Dpump_columnindex 30
#define Dpumpca _p[31]
#define Dpumpca_columnindex 31
#define _g _p[32]
#define _g_columnindex 32
#define _ion_ica	*_ppvar[0]._pval
#define _ion_cai	*_ppvar[1]._pval
#define _ion_dicadv	*_ppvar[2]._pval
#define _style_ca	*((int*)_ppvar[3]._pvoid)
#define diam	*_ppvar[4]._pval
 
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
 /* external NEURON variables */
 /* declaration of user functions */
 static void _hoc_factors(void);
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
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_cdp", _hoc_setdata,
 "factors_cdp", _hoc_factors,
 0, 0
};
 /* declare global and static user variables */
#define DCa DCa_cdp
 double DCa = 0.2;
#define TotalPump TotalPump_cdp
 double TotalPump = 1e-11;
#define TotalBuffer TotalBuffer_cdp
 double TotalBuffer = 0.003;
#define k4 k4_cdp
 double k4 = 0.005;
#define k3 k3_cdp
 double k3 = 1;
#define k2 k2_cdp
 double k2 = 0.005;
#define k1 k1_cdp
 double k1 = 1;
#define k2buf k2buf_cdp
 double k2buf = 0.1;
#define k1buf k1buf_cdp
 double k1buf = 100;
#define vrat vrat_cdp
 double vrat[3];
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "DCa_cdp", "um2/ms",
 "k1buf_cdp", "/mM-ms",
 "k2buf_cdp", "/ms",
 "TotalBuffer_cdp", "mM",
 "k1_cdp", "/mM-ms",
 "k2_cdp", "/ms",
 "k3_cdp", "/ms",
 "k4_cdp", "/mM-ms",
 "TotalPump_cdp", "mol/cm2",
 "vrat_cdp", "1",
 "cai0_cdp", "mM",
 "cao0_cdp", "mM",
 "ca_cdp", "mM",
 "CaBuffer_cdp", "mM",
 "Buffer_cdp", "mM",
 "pump_cdp", "mol/cm2",
 "pumpca_cdp", "mol/cm2",
 "ica_pmp_cdp", "mA/cm2",
 0,0
};
 static double Buffer0 = 0;
 static double CaBuffer0 = 0;
 static double ca0 = 0;
 static double delta_t = 0.01;
 static double pumpca0 = 0;
 static double pump0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "DCa_cdp", &DCa_cdp,
 "k1buf_cdp", &k1buf_cdp,
 "k2buf_cdp", &k2buf_cdp,
 "TotalBuffer_cdp", &TotalBuffer_cdp,
 "k1_cdp", &k1_cdp,
 "k2_cdp", &k2_cdp,
 "k3_cdp", &k3_cdp,
 "k4_cdp", &k4_cdp,
 "TotalPump_cdp", &TotalPump_cdp,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 "vrat_cdp", vrat_cdp, 3,
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
 
#define _cvode_ieq _ppvar[5]._i
 static void _ode_synonym(int, double**, Datum**);
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"cdp",
 "cai0_cdp",
 "cao0_cdp",
 0,
 "ica_pmp_cdp",
 0,
 "ca_cdp[3]",
 "CaBuffer_cdp[3]",
 "Buffer_cdp[3]",
 "pump_cdp",
 "pumpca_cdp",
 0,
 0};
 static Symbol* _morphology_sym;
 static Symbol* _ca_sym;
 static int _type_ica;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 33, _prop);
 	/*initialize range parameters*/
 	cai0 = 0.00018411;
 	cao0 = 2.4;
 	_prop->param = _p;
 	_prop->param_size = 33;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 6, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_morphology_sym);
 	_ppvar[4]._pval = &prop_ion->param[0]; /* diam */
 prop_ion = need_memb(_ca_sym);
  _type_ica = prop_ion->_type;
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[1]._pval = &prop_ion->param[1]; /* cai */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dicadv */
 	_ppvar[3]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for ca */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 "ca_cdp", 1e-07,
 "CaBuffer_cdp", 1e-05,
 "Buffer_cdp", 1e-05,
 "pump_cdp", 1e-15,
 "pumpca_cdp", 1e-15,
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _cadyn_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("ca", -10000.);
 	_morphology_sym = hoc_lookup("morphology");
 	_ca_sym = hoc_lookup("ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 33, 6);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "#ca_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "cvodeieq");
  hoc_register_dparam_semantics(_mechtype, 4, "diam");
 	nrn_writes_conc(_mechtype, 0);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_synonym(_mechtype, _ode_synonym);
 	hoc_register_ldifus1(_difusfunc);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 cdp cadyn.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 
#define FARADAY _nrnunit_FARADAY[_nrnunit_use_legacy_]
static double _nrnunit_FARADAY[2] = {0x1.34c0c8b92a9b7p+3, 9.64853}; /* 9.64853321233100125 */
 
#define PI _nrnunit_PI[_nrnunit_use_legacy_]
static double _nrnunit_PI[2] = {0x1.921fb54442d18p+1, 3.14159}; /* 3.14159265358979312 */
 static double volo = 1e10;
 static double _zfactors_done ;
 static double _zfrat [ 3 ] ;
 static double _zdsq , _zdsqvol ;
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int factors();
 extern double *_getelm();
 
#define _MATELM1(_row,_col)	*(_getelm(_row + 1, _col + 1))
 
#define _RHS1(_arg) _coef1[_arg + 1]
 static double *_coef1;
 
#define _linmat1  0
 static void* _sparseobj1;
 static void* _cvsparseobj1;
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[11], _dlist1[11]; static double *_temp1;
 static int state();
 
static int  factors (  ) {
   double _lr , _ldr2 ;
 _lr = 1.0 / 2.0 ;
   _ldr2 = _lr / ( 3.0 - 1.0 ) / 2.0 ;
   vrat [ 0 ] = 0.0 ;
   _zfrat [ 0 ] = 2.0 * _lr ;
   {int  _li ;for ( _li = 0 ; _li <= 3 - 2 ; _li ++ ) {
     vrat [ _li ] = vrat [ _li ] + PI * ( _lr - _ldr2 / 2.0 ) * 2.0 * _ldr2 ;
     _lr = _lr - _ldr2 ;
     _zfrat [ _li + 1 ] = 2.0 * PI * _lr / ( 2.0 * _ldr2 ) ;
     _lr = _lr - _ldr2 ;
     vrat [ _li + 1 ] = PI * ( _lr + _ldr2 / 2.0 ) * 2.0 * _ldr2 ;
     } }
    return 0; }
 
static void _hoc_factors(void) {
  double _r;
   _r = 1.;
 factors (  );
 hoc_retpushx(_r);
}
 
static int state ()
 {_reset=0;
 {
   double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=1;_i<11;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
}  
_RHS1(10) *= ( ( 1e10 ) * parea) ;
_MATELM1(10, 10) *= ( ( 1e10 ) * parea);  
for (_i=0; _i < 3; _i++) {
  	_RHS1(_i + 1) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 1, _i + 1) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 3; _i++) {
  	_RHS1(_i + 4) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 4, _i + 4) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 3; _i++) {
  	_RHS1(_i + 7) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 7, _i + 7) *= ( diam * diam * vrat [ ((int) _i ) ]);  } }
 /* COMPARTMENT _li , diam * diam * vrat [ ((int) _i ) ] {
     ca CaBuffer Buffer }
   */
 /* COMPARTMENT ( 1e10 ) * parea {
     pump pumpca }
   */
 /* COMPARTMENT volo {
     }
   */
 /* LONGITUDINAL_DIFFUSION _li , DCa * diam * diam * vrat [ ((int) _i ) ] {
     ca }
   */
 /* ~ ca [ 0 ] + pump <-> pumpca ( k1 * parea * ( 1e10 ) , k2 * parea * ( 1e10 ) )*/
 f_flux =  k1 * parea * ( 1e10 ) * pump * ca [ 0] ;
 b_flux =  k2 * parea * ( 1e10 ) * pumpca ;
 _RHS1( 10) -= (f_flux - b_flux);
 _RHS1( 7 +  0) -= (f_flux - b_flux);
 
 _term =  k1 * parea * ( 1e10 ) * ca [ 0] ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 7 +  0 ,10)  += _term;
 _term =  k1 * parea * ( 1e10 ) * pump ;
 _MATELM1( 10 ,7 +  0)  += _term;
 _MATELM1( 7 +  0 ,7 +  0)  += _term;
 _term =  k2 * parea * ( 1e10 ) ;
 _MATELM1( 10 ,0)  -= _term;
 _MATELM1( 7 +  0 ,0)  -= _term;
 /*REACTION*/
  /* ~ pumpca <-> pump + cao ( k3 * parea * ( 1e10 ) , k4 * parea * ( 1e10 ) )*/
 f_flux =  k3 * parea * ( 1e10 ) * pumpca ;
 b_flux =  k4 * parea * ( 1e10 ) * cao * pump ;
 _RHS1( 10) += (f_flux - b_flux);
 
 _term =  k3 * parea * ( 1e10 ) ;
 _MATELM1( 10 ,0)  -= _term;
 _term =  k4 * parea * ( 1e10 ) * cao ;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
   /* pump + pumpca = TotalPump * parea * ( 1e10 ) */
 _RHS1(0) =  TotalPump * parea * ( 1e10 );
 _MATELM1(0, 0) = 1 * ( ( 1e10 ) * parea);
 _RHS1(0) -= pumpca * ( ( 1e10 ) * parea) ;
 _MATELM1(0, 10) = 1 * ( ( 1e10 ) * parea);
 _RHS1(0) -= pump * ( ( 1e10 ) * parea) ;
 /*CONSERVATION*/
 ica_pmp = 2.0 * FARADAY * ( f_flux - b_flux ) / parea ;
   /* ~ ca [ 0 ] < < ( - ( ica - ica_pmp_last ) * PI * diam / ( 2.0 * FARADAY ) )*/
 f_flux = b_flux = 0.;
 _RHS1( 7 +  0) += (b_flux =   ( - ( ica - ica_pmp_last ) * PI * diam / ( 2.0 * FARADAY ) ) );
 /*FLUX*/
  {int  _li ;for ( _li = 0 ; _li <= 3 - 2 ; _li ++ ) {
     /* ~ ca [ _li ] <-> ca [ _li + 1 ] ( DCa * _zfrat [ _li + 1 ] , DCa * _zfrat [ _li + 1 ] )*/
 f_flux =  DCa * _zfrat [ _li + 1 ] * ca [ _li] ;
 b_flux =  DCa * _zfrat [ _li + 1 ] * ca [ _li + 1] ;
 _RHS1( 7 +  _li) -= (f_flux - b_flux);
 _RHS1( 7 +  _li + 1) += (f_flux - b_flux);
 
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 7 +  _li ,7 +  _li)  += _term;
 _MATELM1( 7 +  _li + 1 ,7 +  _li)  -= _term;
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 7 +  _li ,7 +  _li + 1)  -= _term;
 _MATELM1( 7 +  _li + 1 ,7 +  _li + 1)  += _term;
 /*REACTION*/
  } }
   _zdsq = diam * diam ;
   {int  _li ;for ( _li = 0 ; _li <= 3 - 1 ; _li ++ ) {
     _zdsqvol = _zdsq * vrat [ _li ] ;
     /* ~ ca [ _li ] + Buffer [ _li ] <-> CaBuffer [ _li ] ( k1buf * _zdsqvol , k2buf * _zdsqvol )*/
 f_flux =  k1buf * _zdsqvol * Buffer [ _li] * ca [ _li] ;
 b_flux =  k2buf * _zdsqvol * CaBuffer [ _li] ;
 _RHS1( 1 +  _li) -= (f_flux - b_flux);
 _RHS1( 7 +  _li) -= (f_flux - b_flux);
 _RHS1( 4 +  _li) += (f_flux - b_flux);
 
 _term =  k1buf * _zdsqvol * ca [ _li] ;
 _MATELM1( 1 +  _li ,1 +  _li)  += _term;
 _MATELM1( 7 +  _li ,1 +  _li)  += _term;
 _MATELM1( 4 +  _li ,1 +  _li)  -= _term;
 _term =  k1buf * _zdsqvol * Buffer [ _li] ;
 _MATELM1( 1 +  _li ,7 +  _li)  += _term;
 _MATELM1( 7 +  _li ,7 +  _li)  += _term;
 _MATELM1( 4 +  _li ,7 +  _li)  -= _term;
 _term =  k2buf * _zdsqvol ;
 _MATELM1( 1 +  _li ,4 +  _li)  -= _term;
 _MATELM1( 7 +  _li ,4 +  _li)  -= _term;
 _MATELM1( 4 +  _li ,4 +  _li)  += _term;
 /*REACTION*/
  } }
   cai = ca [ 0 ] ;
     } return _reset;
 }
 
/*CVODE ode begin*/
 static int _ode_spec1() {_reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<11;_i++) _p[_dlist1[_i]] = 0.0;}
 /* COMPARTMENT _li , diam * diam * vrat [ ((int) _i ) ] {
   ca CaBuffer Buffer }
 */
 /* COMPARTMENT ( 1e10 ) * parea {
   pump pumpca }
 */
 /* COMPARTMENT volo {
   }
 */
 /* LONGITUDINAL_DIFFUSION _li , DCa * diam * diam * vrat [ ((int) _i ) ] {
   ca }
 */
 /* ~ ca [ 0 ] + pump <-> pumpca ( k1 * parea * ( 1e10 ) , k2 * parea * ( 1e10 ) )*/
 f_flux =  k1 * parea * ( 1e10 ) * pump * ca [ 0] ;
 b_flux =  k2 * parea * ( 1e10 ) * pumpca ;
 Dpump -= (f_flux - b_flux);
 Dca [ 0] -= (f_flux - b_flux);
 Dpumpca += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ pumpca <-> pump + cao ( k3 * parea * ( 1e10 ) , k4 * parea * ( 1e10 ) )*/
 f_flux =  k3 * parea * ( 1e10 ) * pumpca ;
 b_flux =  k4 * parea * ( 1e10 ) * cao * pump ;
 Dpumpca -= (f_flux - b_flux);
 Dpump += (f_flux - b_flux);
 
 /*REACTION*/
   /* pump + pumpca = TotalPump * parea * ( 1e10 ) */
 /*CONSERVATION*/
 ica_pmp = 2.0 * FARADAY * ( f_flux - b_flux ) / parea ;
 /* ~ ca [ 0 ] < < ( - ( ica - ica_pmp_last ) * PI * diam / ( 2.0 * FARADAY ) )*/
 f_flux = b_flux = 0.;
 Dca [ 0] += (b_flux =   ( - ( ica - ica_pmp_last ) * PI * diam / ( 2.0 * FARADAY ) ) );
 /*FLUX*/
  {int  _li ;for ( _li = 0 ; _li <= 3 - 2 ; _li ++ ) {
   /* ~ ca [ _li ] <-> ca [ _li + 1 ] ( DCa * _zfrat [ _li + 1 ] , DCa * _zfrat [ _li + 1 ] )*/
 f_flux =  DCa * _zfrat [ _li + 1 ] * ca [ _li] ;
 b_flux =  DCa * _zfrat [ _li + 1 ] * ca [ _li + 1] ;
 Dca [ _li] -= (f_flux - b_flux);
 Dca [ _li + 1] += (f_flux - b_flux);
 
 /*REACTION*/
  } }
 _zdsq = diam * diam ;
 {int  _li ;for ( _li = 0 ; _li <= 3 - 1 ; _li ++ ) {
   _zdsqvol = _zdsq * vrat [ _li ] ;
   /* ~ ca [ _li ] + Buffer [ _li ] <-> CaBuffer [ _li ] ( k1buf * _zdsqvol , k2buf * _zdsqvol )*/
 f_flux =  k1buf * _zdsqvol * Buffer [ _li] * ca [ _li] ;
 b_flux =  k2buf * _zdsqvol * CaBuffer [ _li] ;
 DBuffer [ _li] -= (f_flux - b_flux);
 Dca [ _li] -= (f_flux - b_flux);
 DCaBuffer [ _li] += (f_flux - b_flux);
 
 /*REACTION*/
  } }
 cai = ca [ 0 ] ;
 _p[_dlist1[0]] /= ( ( 1e10 ) * parea);
 for (_i=0; _i < 3; _i++) { _p[_dlist1[_i + 1]] /= ( diam * diam * vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 3; _i++) { _p[_dlist1[_i + 4]] /= ( diam * diam * vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 3; _i++) { _p[_dlist1[_i + 7]] /= ( diam * diam * vrat [ ((int) _i ) ]);}
 _p[_dlist1[10]] /= ( ( 1e10 ) * parea);
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1() {_reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<11;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
}  
_RHS1(0) *= ( ( 1e10 ) * parea) ;
_MATELM1(0, 0) *= ( ( 1e10 ) * parea); 
_RHS1(10) *= ( ( 1e10 ) * parea) ;
_MATELM1(10, 10) *= ( ( 1e10 ) * parea);  
for (_i=0; _i < 3; _i++) {
  	_RHS1(_i + 1) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 1, _i + 1) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 3; _i++) {
  	_RHS1(_i + 4) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 4, _i + 4) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 3; _i++) {
  	_RHS1(_i + 7) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 7, _i + 7) *= ( diam * diam * vrat [ ((int) _i ) ]);  } }
 /* COMPARTMENT _li , diam * diam * vrat [ ((int) _i ) ] {
 ca CaBuffer Buffer }
 */
 /* COMPARTMENT ( 1e10 ) * parea {
 pump pumpca }
 */
 /* COMPARTMENT volo {
 }
 */
 /* LONGITUDINAL_DIFFUSION _li , DCa * diam * diam * vrat [ ((int) _i ) ] {
 ca }
 */
 /* ~ ca [ 0 ] + pump <-> pumpca ( k1 * parea * ( 1e10 ) , k2 * parea * ( 1e10 ) )*/
 _term =  k1 * parea * ( 1e10 ) * ca [ 0] ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 7 +  0 ,10)  += _term;
 _MATELM1( 0 ,10)  -= _term;
 _term =  k1 * parea * ( 1e10 ) * pump ;
 _MATELM1( 10 ,7 +  0)  += _term;
 _MATELM1( 7 +  0 ,7 +  0)  += _term;
 _MATELM1( 0 ,7 +  0)  -= _term;
 _term =  k2 * parea * ( 1e10 ) ;
 _MATELM1( 10 ,0)  -= _term;
 _MATELM1( 7 +  0 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ pumpca <-> pump + cao ( k3 * parea * ( 1e10 ) , k4 * parea * ( 1e10 ) )*/
 _term =  k3 * parea * ( 1e10 ) ;
 _MATELM1( 0 ,0)  += _term;
 _MATELM1( 10 ,0)  -= _term;
 _term =  k4 * parea * ( 1e10 ) * cao ;
 _MATELM1( 0 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /* ~ ca [ 0 ] < < ( - ( ica - ica_pmp_last ) * PI * diam / ( 2.0 * FARADAY ) )*/
 /*FLUX*/
  {int  _li ;for ( _li = 0 ; _li <= 3 - 2 ; _li ++ ) {
 /* ~ ca [ _li ] <-> ca [ _li + 1 ] ( DCa * _zfrat [ _li + 1 ] , DCa * _zfrat [ _li + 1 ] )*/
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 7 +  _li ,7 +  _li)  += _term;
 _MATELM1( 7 +  _li + 1 ,7 +  _li)  -= _term;
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 7 +  _li ,7 +  _li + 1)  -= _term;
 _MATELM1( 7 +  _li + 1 ,7 +  _li + 1)  += _term;
 /*REACTION*/
  } }
 _zdsq = diam * diam ;
 {int  _li ;for ( _li = 0 ; _li <= 3 - 1 ; _li ++ ) {
 _zdsqvol = _zdsq * vrat [ _li ] ;
 /* ~ ca [ _li ] + Buffer [ _li ] <-> CaBuffer [ _li ] ( k1buf * _zdsqvol , k2buf * _zdsqvol )*/
 _term =  k1buf * _zdsqvol * ca [ _li] ;
 _MATELM1( 1 +  _li ,1 +  _li)  += _term;
 _MATELM1( 7 +  _li ,1 +  _li)  += _term;
 _MATELM1( 4 +  _li ,1 +  _li)  -= _term;
 _term =  k1buf * _zdsqvol * Buffer [ _li] ;
 _MATELM1( 1 +  _li ,7 +  _li)  += _term;
 _MATELM1( 7 +  _li ,7 +  _li)  += _term;
 _MATELM1( 4 +  _li ,7 +  _li)  -= _term;
 _term =  k2buf * _zdsqvol ;
 _MATELM1( 1 +  _li ,4 +  _li)  -= _term;
 _MATELM1( 7 +  _li ,4 +  _li)  -= _term;
 _MATELM1( 4 +  _li ,4 +  _li)  += _term;
 /*REACTION*/
  } }
 cai = ca [ 0 ] ;
   } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 11;}
 
static void _ode_spec(NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ica = _ion_ica;
  cai = _ion_cai;
     _ode_spec1 ();
  _ion_cai = cai;
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 11; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 static void _ode_synonym(int _cnt, double** _pp, Datum** _ppd) { 
 	int _i; 
	for (_i=0; _i < _cnt; ++_i) {_p = _pp[_i]; _ppvar = _ppd[_i];
 _ion_cai =  ca [ 0 ] ;
 }}
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _cvode_sparse(&_cvsparseobj1, 11, _dlist1, _p, _ode_matsol1, &_coef1);
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
  ica = _ion_ica;
  cai = _ion_cai;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 1);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 2, 4);
 }
 static void* _difspace1;
extern double nrn_nernst_coef();
static double _difcoef1(int _i, double* _p, Datum* _ppvar, double* _pdvol, double* _pdfcdc, Datum* _thread, NrnThread* _nt) {
   *_pdvol =  diam * diam * vrat [ ((int) _i ) ] ;
 if (_i ==  0) {
  *_pdfcdc = nrn_nernst_coef(_type_ica)*( ( - ( _ion_dicadv  - ica_pmp_last ) * PI * diam / ( 2.0 * FARADAY ) ));
 }else{ *_pdfcdc=0.;}
   return DCa * diam * diam * vrat [ ((int) _i ) ] ;
}
 static void _difusfunc(ldifusfunc2_t _f, NrnThread* _nt) {int _i;
  for (_i=0; _i < 3; ++_i) (*_f)(_mechtype, _difcoef1, &_difspace1, _i,  3, 21 , _nt);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
 for (_i=0; _i<3; _i++) Buffer[_i] = Buffer0;
 for (_i=0; _i<3; _i++) CaBuffer[_i] = CaBuffer0;
 for (_i=0; _i<3; _i++) ca[_i] = ca0;
  pumpca = pumpca0;
  pump = pump0;
 {
   cai = cai0 ;
   cao = cao0 ;
   }
 {
   if ( _zfactors_done  == 0.0 ) {
     _zfactors_done = 1.0 ;
     factors ( _threadargs_ ) ;
     }
   Kd = k1buf / k2buf ;
   B0 = TotalBuffer / ( 1.0 + Kd * cai ) ;
   {int  _li ;for ( _li = 0 ; _li <= 3 - 1 ; _li ++ ) {
     ca [ _li ] = cai ;
     Buffer [ _li ] = B0 ;
     CaBuffer [ _li ] = TotalBuffer - B0 ;
     } }
   parea = PI * diam ;
   ica = 0.0 ;
   ica_pmp = 0.0 ;
   ica_pmp_last = 0.0 ;
   error = _ss_sparse(&_sparseobj1, 11, _slist1, _dlist1, _p, &t, dt, state,&_coef1, _linmat1);
 if(error){fprintf(stderr,"at line 100 in file cadyn.mod:\n\n"); nrn_complain(_p); abort_run(error);}
    if (secondorder) {
    int _i;
    for (_i = 0; _i < 11; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
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
  ica = _ion_ica;
  cai = _ion_cai;
 initmodel();
  _ion_cai = cai;
   nrn_wrote_conc(_ca_sym, (&(_ion_cai)) - 1, _style_ca);
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   ica_pmp_last = ica_pmp ;
   ica = ica_pmp ;
   }
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
  ica = _ion_ica;
  cai = _ion_cai;
if (_nt->_vcv) { _ode_spec1(); }
 _g = _nrn_current(_v + .001);
 	{ double _dica;
  _dica = ica;
 _rhs = _nrn_current(_v);
  _ion_dicadv += (_dica - ica)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_cai = cai;
  _ion_ica += ica ;
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
  ica = _ion_ica;
  cai = _ion_cai;
 { error = sparse(&_sparseobj1, 11, _slist1, _dlist1, _p, &t, dt, state,&_coef1, _linmat1);
 if(error){fprintf(stderr,"at line 71 in file cadyn.mod:\n  SOLVE state METHOD sparse\n"); nrn_complain(_p); abort_run(error);}
    if (secondorder) {
    int _i;
    for (_i = 0; _i < 11; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 }  _ion_cai = cai;
 }}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = pumpca_columnindex;  _dlist1[0] = Dpumpca_columnindex;
 for(_i=0;_i<3;_i++){_slist1[1+_i] = Buffer_columnindex + _i;  _dlist1[1+_i] = DBuffer_columnindex + _i;}
 for(_i=0;_i<3;_i++){_slist1[4+_i] = CaBuffer_columnindex + _i;  _dlist1[4+_i] = DCaBuffer_columnindex + _i;}
 for(_i=0;_i<3;_i++){_slist1[7+_i] = ca_columnindex + _i;  _dlist1[7+_i] = Dca_columnindex + _i;}
 _slist1[10] = pump_columnindex;  _dlist1[10] = Dpump_columnindex;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "cadyn.mod";
static const char* nmodl_file_text = 
  ": Calcium ion accumulation with radial and longitudinal diffusion and pump\n"
  "\n"
  "NEURON {\n"
  "  SUFFIX cdp\n"
  "  USEION ca READ ica WRITE cai, ica\n"
  "  RANGE ica_pmp, cai0, cao0\n"
  "  GLOBAL vrat, TotalBuffer, TotalPump\n"
  "}\n"
  "\n"
  "DEFINE Nannuli 3\n"
  "\n"
  "UNITS {\n"
  "  (mol)   = (1)\n"
  "  (molar) = (1/liter)\n"
  "  (mM)    = (millimolar)\n"
  "  (um)    = (micron)\n"
  "  (mA)    = (milliamp)\n"
  "  FARADAY = (faraday)  (10000 coulomb)\n"
  "  PI      = (pi)       (1)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "  DCa   = 0.2 (um2/ms)\n"
  "  k1buf = 100 (/mM-ms)\n"
  "  k2buf = 0.1 (/ms)\n"
  "  TotalBuffer = 0.003  (mM)\n"
  "  k1    = 1       (/mM-ms)\n"
  "  k2    = 0.005   (/ms)\n"
  "  k3    = 1       (/ms)\n"
  "  k4    = 0.005   (/mM-ms)\n"
  "  cai0 = 0.00018411 (mM)\n"
  "  cao0 = 2.4 (mM)\n"
  "  TotalPump = 1e-11  (mol/cm2)\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "  diam      (um)\n"
  "  ica       (mA/cm2)\n"
  "  ica_pmp   (mA/cm2)\n"
  "  cai (mM)\n"
  "  cao (mM)\n"
  "  ica_pmp_last   (mA/cm2)\n"
  "  parea     (um)     : pump area per unit length\n"
  "  vrat[Nannuli]  (1) : dimensionless\n"
  "                     : numeric value of vrat[i] equals the volume \n"
  "                     : of annulus i of a 1um diameter cylinder\n"
  "                     : multiply by diam^2 to get volume per um length\n"
  "  Kd        (/mM)\n"
  "  B0        (mM)\n"
  "}\n"
  "\n"
  "CONSTANT { volo = 1e10 (um2) }\n"
  " \n"
  "INITIAL{\n"
  "  cai = cai0\n"
  "  cao = cao0\n"
  "}\n"
  "\n"
  "STATE {\n"
  "  : ca[0] is equivalent to cai\n"
  "  : ca[] are very small, so specify absolute tolerance\n"
  "  : let it be ~1.5 - 2 orders of magnitude smaller than baseline level\n"
  "  ca[Nannuli]       (mM) <1e-7>\n"
  "  CaBuffer[Nannuli] (mM) <1e-5>\n"
  "  Buffer[Nannuli]   (mM) <1e-5>\n"
  "  pump              (mol/cm2) <1e-15>\n"
  "  pumpca            (mol/cm2) <1e-15>\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "  SOLVE state METHOD sparse\n"
  "  ica_pmp_last = ica_pmp\n"
  "  ica = ica_pmp\n"
  "}\n"
  "\n"
  "LOCAL factors_done\n"
  "\n"
  "INITIAL {\n"
  "   if (factors_done == 0) {  : flag becomes 1 in the first segment\n"
  "      factors_done = 1       :   all subsequent segments will have\n"
  "      factors()              :   vrat = 0 unless vrat is GLOBAL\n"
  "   }\n"
  "\n"
  "  Kd = k1buf/k2buf\n"
  "  B0 = TotalBuffer/(1 + Kd*cai)\n"
  "\n"
  "  FROM i=0 TO Nannuli-1 {\n"
  "    ca[i] = cai\n"
  "    Buffer[i] = B0\n"
  "    CaBuffer[i] = TotalBuffer - B0\n"
  "  }\n"
  "\n"
  "  parea = PI*diam\n"
  "\n"
  "\n"
  "  ica=0\n"
  "  ica_pmp = 0\n"
  "  ica_pmp_last = 0\n"
  "  SOLVE state STEADYSTATE sparse\n"
  "\n"
  "}\n"
  "\n"
  "LOCAL frat[Nannuli]  : scales the rate constants for model geometry\n"
  "PROCEDURE factors() {\n"
  "  LOCAL r, dr2\n"
  "  r = 1/2                : starts at edge (half diam)\n"
  "  dr2 = r/(Nannuli-1)/2  : full thickness of outermost annulus,\n"
  "                         : half thickness of all other annuli\n"
  "  vrat[0] = 0\n"
  "  frat[0] = 2*r\n"
  "  FROM i=0 TO Nannuli-2 {\n"
  "    vrat[i] = vrat[i] + PI*(r-dr2/2)*2*dr2  : interior half\n"
  "    r = r - dr2\n"
  "    frat[i+1] = 2*PI*r/(2*dr2)  : outer radius of annulus\n"
  "                                : div by distance between centers\n"
  "    r = r - dr2\n"
  "    vrat[i+1] = PI*(r+dr2/2)*2*dr2  : outer half of annulus\n"
  "  }\n"
  "}\n"
  "\n"
  "LOCAL dsq, dsqvol  : can't define local variable in KINETIC block\n"
  "                   :   or use in COMPARTMENT statement\n"
  "\n"
  "KINETIC state {\n"
  "  COMPARTMENT i, diam*diam*vrat[i] {ca CaBuffer Buffer}\n"
  "  COMPARTMENT (1e10)*parea {pump pumpca}\n"
  "  COMPARTMENT volo {cao}\n"
  "  LONGITUDINAL_DIFFUSION i, DCa*diam*diam*vrat[i] {ca}\n"
  "\n"
  "  :pump\n"
  "  ~ ca[0] + pump <-> pumpca  (k1*parea*(1e10), k2*parea*(1e10))\n"
  "  ~ pumpca <-> pump + cao    (k3*parea*(1e10), k4*parea*(1e10))\n"
  "  CONSERVE pump + pumpca = TotalPump * parea * (1e10)\n"
  "  ica_pmp = 2*FARADAY*(f_flux - b_flux)/parea\n"
  "\n"
  "  : all currents except pump\n"
  "  : ica is Ca efflux\n"
  "  ~ ca[0] << (-(ica - ica_pmp_last)*PI*diam/(2*FARADAY))\n"
  "  FROM i=0 TO Nannuli-2 {\n"
  "    ~ ca[i] <-> ca[i+1]  (DCa*frat[i+1], DCa*frat[i+1])\n"
  "  }\n"
  "  dsq = diam*diam\n"
  "  FROM i=0 TO Nannuli-1 {\n"
  "    dsqvol = dsq*vrat[i]\n"
  "    ~ ca[i] + Buffer[i] <-> CaBuffer[i]  (k1buf*dsqvol, k2buf*dsqvol)\n"
  "  }\n"
  "  cai = ca[0]\n"
  "}\n"
  ;
#endif
