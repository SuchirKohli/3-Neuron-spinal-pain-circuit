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
 
#define nrn_init _nrn_init__a7
#define _nrn_initial _nrn_initial__a7
#define nrn_cur _nrn_cur__a7
#define _nrn_current _nrn_current__a7
#define nrn_jacob _nrn_jacob__a7
#define nrn_state _nrn_state__a7
#define _net_receive _net_receive__a7 
#define kstates kstates__a7 
 
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
#define curr _p[3]
#define curr_columnindex 3
#define g _p[4]
#define g_columnindex 4
#define ica _p[5]
#define ica_columnindex 5
#define ina _p[6]
#define ina_columnindex 6
#define ik _p[7]
#define ik_columnindex 7
#define C5 _p[8]
#define C5_columnindex 8
#define C4 _p[9]
#define C4_columnindex 9
#define C3 _p[10]
#define C3_columnindex 10
#define C2 _p[11]
#define C2_columnindex 11
#define C1 _p[12]
#define C1_columnindex 12
#define C0 _p[13]
#define C0_columnindex 13
#define O1 _p[14]
#define O1_columnindex 14
#define O2 _p[15]
#define O2_columnindex 15
#define O3 _p[16]
#define O3_columnindex 16
#define O4 _p[17]
#define O4_columnindex 17
#define O5 _p[18]
#define O5_columnindex 18
#define D0 _p[19]
#define D0_columnindex 19
#define D1 _p[20]
#define D1_columnindex 20
#define D2 _p[21]
#define D2_columnindex 21
#define D3 _p[22]
#define D3_columnindex 22
#define D4 _p[23]
#define D4_columnindex 23
#define D5 _p[24]
#define D5_columnindex 24
#define SD0 _p[25]
#define SD0_columnindex 25
#define SD1 _p[26]
#define SD1_columnindex 26
#define SD2 _p[27]
#define SD2_columnindex 27
#define SD3 _p[28]
#define SD3_columnindex 28
#define SD4 _p[29]
#define SD4_columnindex 29
#define SD5 _p[30]
#define SD5_columnindex 30
#define tr _p[31]
#define tr_columnindex 31
#define Rb1 _p[32]
#define Rb1_columnindex 32
#define Rb2 _p[33]
#define Rb2_columnindex 33
#define Rb3 _p[34]
#define Rb3_columnindex 34
#define Rb4 _p[35]
#define Rb4_columnindex 35
#define Rb5 _p[36]
#define Rb5_columnindex 36
#define DC5 _p[37]
#define DC5_columnindex 37
#define DC4 _p[38]
#define DC4_columnindex 38
#define DC3 _p[39]
#define DC3_columnindex 39
#define DC2 _p[40]
#define DC2_columnindex 40
#define DC1 _p[41]
#define DC1_columnindex 41
#define DC0 _p[42]
#define DC0_columnindex 42
#define DO1 _p[43]
#define DO1_columnindex 43
#define DO2 _p[44]
#define DO2_columnindex 44
#define DO3 _p[45]
#define DO3_columnindex 45
#define DO4 _p[46]
#define DO4_columnindex 46
#define DO5 _p[47]
#define DO5_columnindex 47
#define DD0 _p[48]
#define DD0_columnindex 48
#define DD1 _p[49]
#define DD1_columnindex 49
#define DD2 _p[50]
#define DD2_columnindex 50
#define DD3 _p[51]
#define DD3_columnindex 51
#define DD4 _p[52]
#define DD4_columnindex 52
#define DD5 _p[53]
#define DD5_columnindex 53
#define DSD0 _p[54]
#define DSD0_columnindex 54
#define DSD1 _p[55]
#define DSD1_columnindex 55
#define DSD2 _p[56]
#define DSD2_columnindex 56
#define DSD3 _p[57]
#define DSD3_columnindex 57
#define DSD4 _p[58]
#define DSD4_columnindex 58
#define DSD5 _p[59]
#define DSD5_columnindex 59
#define _g _p[60]
#define _g_columnindex 60
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
#define Erev Erev_a7
 double Erev = 0;
#define Rsd5sd4 Rsd5sd4_a7
 double Rsd5sd4 = 0.25;
#define Rsd4sd3 Rsd4sd3_a7
 double Rsd4sd3 = 0.2;
#define Rsd3sd2 Rsd3sd2_a7
 double Rsd3sd2 = 0.15;
#define Rsd2sd1 Rsd2sd1_a7
 double Rsd2sd1 = 0.1;
#define Rsd1sd0 Rsd1sd0_a7
 double Rsd1sd0 = 0.05;
#define Rsd5 Rsd5_a7
 double Rsd5 = 0.00064;
#define Rsd4 Rsd4_a7
 double Rsd4 = 0.00032;
#define Rsd3 Rsd3_a7
 double Rsd3 = 0.00016;
#define Rsd2 Rsd2_a7
 double Rsd2 = 8e-05;
#define Rsd1 Rsd1_a7
 double Rsd1 = 4e-05;
#define Rsd0 Rsd0_a7
 double Rsd0 = 2e-05;
#define Rrsd5 Rrsd5_a7
 double Rrsd5 = 3.125e-05;
#define Rrsd4 Rrsd4_a7
 double Rrsd4 = 6.25e-05;
#define Rrsd3 Rrsd3_a7
 double Rrsd3 = 0.000125;
#define Rrsd2 Rrsd2_a7
 double Rrsd2 = 0.00025;
#define Rrsd1 Rrsd1_a7
 double Rrsd1 = 0.0005;
#define Rrsd0 Rrsd0_a7
 double Rrsd0 = 0.001;
#define Rd5d4 Rd5d4_a7
 double Rd5d4 = 1;
#define Rd4d3 Rd4d3_a7
 double Rd4d3 = 0.8;
#define Rd3d2 Rd3d2_a7
 double Rd3d2 = 0.6;
#define Rd2d1 Rd2d1_a7
 double Rd2d1 = 0.4;
#define Rd1d0 Rd1d0_a7
 double Rd1d0 = 0.2;
#define Rr5 Rr5_a7
 double Rr5 = 0.0016;
#define Rr4 Rr4_a7
 double Rr4 = 0.008;
#define Rr3 Rr3_a7
 double Rr3 = 0.04;
#define Rr2 Rr2_a7
 double Rr2 = 0.2;
#define Rr1 Rr1_a7
 double Rr1 = 1;
#define Rr0 Rr0_a7
 double Rr0 = 5;
#define Rd5 Rd5_a7
 double Rd5 = 15.625;
#define Rd4 Rd4_a7
 double Rd4 = 3.125;
#define Rd3 Rd3_a7
 double Rd3 = 0.625;
#define Rd2 Rd2_a7
 double Rd2 = 0.125;
#define Rd1 Rd1_a7
 double Rd1 = 0.025;
#define Rd0 Rd0_a7
 double Rd0 = 0.005;
#define Rc5 Rc5_a7
 double Rc5 = 0.02;
#define Rc4 Rc4_a7
 double Rc4 = 0.02;
#define Rc3 Rc3_a7
 double Rc3 = 0.02;
#define Rc2 Rc2_a7
 double Rc2 = 0.02;
#define Rc1 Rc1_a7
 double Rc1 = 0.02;
#define Ro5 Ro5_a7
 double Ro5 = 8;
#define Ro4 Ro4_a7
 double Ro4 = 0.4;
#define Ro3 Ro3_a7
 double Ro3 = 0.02;
#define Ro2 Ro2_a7
 double Ro2 = 0.001;
#define Ro1 Ro1_a7
 double Ro1 = 5e-05;
#define Ru5 Ru5_a7
 double Ru5 = 25;
#define Ru4 Ru4_a7
 double Ru4 = 20;
#define Ru3 Ru3_a7
 double Ru3 = 15;
#define Ru2 Ru2_a7
 double Ru2 = 10;
#define Ru1 Ru1_a7
 double Ru1 = 0.5;
#define rb5 rb5_a7
 double rb5 = 0.01;
#define rb4 rb4_a7
 double rb4 = 0.02;
#define rb3 rb3_a7
 double rb3 = 0.03;
#define rb2 rb2_a7
 double rb2 = 0.04;
#define rb1 rb1_a7
 double rb1 = 0.05;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "Erev_a7", "mV",
 "rb1_a7", "/mM",
 "rb2_a7", "/mM",
 "rb3_a7", "/mM",
 "rb4_a7", "/mM",
 "rb5_a7", "/mM",
 "Ru1_a7", "/ms",
 "Ru2_a7", "/ms",
 "Ru3_a7", "/ms",
 "Ru4_a7", "/ms",
 "Ru5_a7", "/ms",
 "Rd0_a7", "/ms",
 "Rd1_a7", "/ms",
 "Rd2_a7", "/ms",
 "Rd3_a7", "/ms",
 "Rd4_a7", "/ms",
 "Rd5_a7", "/ms",
 "Rr0_a7", "/ms",
 "Rr1_a7", "/ms",
 "Rr2_a7", "/ms",
 "Rr3_a7", "/ms",
 "Rr4_a7", "/ms",
 "Rr5_a7", "/ms",
 "Ro1_a7", "/ms",
 "Ro2_a7", "/ms",
 "Ro3_a7", "/ms",
 "Ro4_a7", "/ms",
 "Ro5_a7", "/ms",
 "Rc1_a7", "/ms",
 "Rc2_a7", "/ms",
 "Rc3_a7", "/ms",
 "Rc4_a7", "/ms",
 "Rc5_a7", "/ms",
 "Rd1d0_a7", "/ms",
 "Rd2d1_a7", "/ms",
 "Rd3d2_a7", "/ms",
 "Rd4d3_a7", "/ms",
 "Rd5d4_a7", "/ms",
 "Rrsd0_a7", "/ms",
 "Rrsd1_a7", "/ms",
 "Rrsd2_a7", "/ms",
 "Rrsd3_a7", "/ms",
 "Rrsd4_a7", "/ms",
 "Rrsd5_a7", "/ms",
 "Rsd0_a7", "/ms",
 "Rsd1_a7", "/ms",
 "Rsd2_a7", "/ms",
 "Rsd3_a7", "/ms",
 "Rsd4_a7", "/ms",
 "Rsd5_a7", "/ms",
 "Rsd1sd0_a7", "/ms",
 "Rsd2sd1_a7", "/ms",
 "Rsd3sd2_a7", "/ms",
 "Rsd4sd3_a7", "/ms",
 "Rsd5sd4_a7", "/ms",
 "gmax", "pS",
 "tdur", "ms",
 "del", "ms",
 "curr", "nA",
 "g", "pS",
 "ica", "nA",
 "ina", "nA",
 "ik", "nA",
 "C", "mM",
 0,0
};
 static double C00 = 0;
 static double C10 = 0;
 static double C20 = 0;
 static double C30 = 0;
 static double C40 = 0;
 static double C50 = 0;
 static double D50 = 0;
 static double D40 = 0;
 static double D30 = 0;
 static double D20 = 0;
 static double D10 = 0;
 static double D00 = 0;
 static double O50 = 0;
 static double O40 = 0;
 static double O30 = 0;
 static double O20 = 0;
 static double O10 = 0;
 static double SD50 = 0;
 static double SD40 = 0;
 static double SD30 = 0;
 static double SD20 = 0;
 static double SD10 = 0;
 static double SD00 = 0;
 static double delta_t = 0.01;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "Erev_a7", &Erev_a7,
 "rb1_a7", &rb1_a7,
 "rb2_a7", &rb2_a7,
 "rb3_a7", &rb3_a7,
 "rb4_a7", &rb4_a7,
 "rb5_a7", &rb5_a7,
 "Ru1_a7", &Ru1_a7,
 "Ru2_a7", &Ru2_a7,
 "Ru3_a7", &Ru3_a7,
 "Ru4_a7", &Ru4_a7,
 "Ru5_a7", &Ru5_a7,
 "Rd0_a7", &Rd0_a7,
 "Rd1_a7", &Rd1_a7,
 "Rd2_a7", &Rd2_a7,
 "Rd3_a7", &Rd3_a7,
 "Rd4_a7", &Rd4_a7,
 "Rd5_a7", &Rd5_a7,
 "Rr0_a7", &Rr0_a7,
 "Rr1_a7", &Rr1_a7,
 "Rr2_a7", &Rr2_a7,
 "Rr3_a7", &Rr3_a7,
 "Rr4_a7", &Rr4_a7,
 "Rr5_a7", &Rr5_a7,
 "Ro1_a7", &Ro1_a7,
 "Ro2_a7", &Ro2_a7,
 "Ro3_a7", &Ro3_a7,
 "Ro4_a7", &Ro4_a7,
 "Ro5_a7", &Ro5_a7,
 "Rc1_a7", &Rc1_a7,
 "Rc2_a7", &Rc2_a7,
 "Rc3_a7", &Rc3_a7,
 "Rc4_a7", &Rc4_a7,
 "Rc5_a7", &Rc5_a7,
 "Rd1d0_a7", &Rd1d0_a7,
 "Rd2d1_a7", &Rd2d1_a7,
 "Rd3d2_a7", &Rd3d2_a7,
 "Rd4d3_a7", &Rd4d3_a7,
 "Rd5d4_a7", &Rd5d4_a7,
 "Rrsd0_a7", &Rrsd0_a7,
 "Rrsd1_a7", &Rrsd1_a7,
 "Rrsd2_a7", &Rrsd2_a7,
 "Rrsd3_a7", &Rrsd3_a7,
 "Rrsd4_a7", &Rrsd4_a7,
 "Rrsd5_a7", &Rrsd5_a7,
 "Rsd0_a7", &Rsd0_a7,
 "Rsd1_a7", &Rsd1_a7,
 "Rsd2_a7", &Rsd2_a7,
 "Rsd3_a7", &Rsd3_a7,
 "Rsd4_a7", &Rsd4_a7,
 "Rsd5_a7", &Rsd5_a7,
 "Rsd1sd0_a7", &Rsd1sd0_a7,
 "Rsd2sd1_a7", &Rsd2sd1_a7,
 "Rsd3sd2_a7", &Rsd3sd2_a7,
 "Rsd4sd3_a7", &Rsd4sd3_a7,
 "Rsd5sd4_a7", &Rsd5sd4_a7,
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
"a7",
 "gmax",
 "tdur",
 "del",
 0,
 "curr",
 "g",
 "ica",
 "ina",
 "ik",
 0,
 "C5",
 "C4",
 "C3",
 "C2",
 "C1",
 "C0",
 "O1",
 "O2",
 "O3",
 "O4",
 "O5",
 "D0",
 "D1",
 "D2",
 "D3",
 "D4",
 "D5",
 "SD0",
 "SD1",
 "SD2",
 "SD3",
 "SD4",
 "SD5",
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
 	_p = nrn_prop_data_alloc(_mechtype, 61, _prop);
 	/*initialize range parameters*/
 	gmax = 95;
 	tdur = 5;
 	del = 0;
  }
 	_prop->param = _p;
 	_prop->param_size = 61;
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

 void _a7_reg() {
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
  hoc_register_prop_size(_mechtype, 61, 10);
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
 	ivoc_help("help ?1 a7 a7.mod\n");
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
 static int _slist1[23], _dlist1[23]; static double *_temp1;
 static int kstates();
 
static int kstates ()
 {_reset=0;
 {
   double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=1;_i<23;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 Rb1 = rb1 * C ;
   Rb2 = rb2 * C ;
   Rb3 = rb3 * C ;
   Rb4 = rb4 * C ;
   Rb5 = rb5 * C ;
   /* ~ C5 <-> C4 ( Rb1 , Ru1 )*/
 f_flux =  Rb1 * C5 ;
 b_flux =  Ru1 * C4 ;
 _RHS1( 6) -= (f_flux - b_flux);
 _RHS1( 5) += (f_flux - b_flux);
 
 _term =  Rb1 ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 5 ,6)  -= _term;
 _term =  Ru1 ;
 _MATELM1( 6 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ C4 <-> C3 ( Rb2 , Ru2 )*/
 f_flux =  Rb2 * C4 ;
 b_flux =  Ru2 * C3 ;
 _RHS1( 5) -= (f_flux - b_flux);
 _RHS1( 4) += (f_flux - b_flux);
 
 _term =  Rb2 ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 4 ,5)  -= _term;
 _term =  Ru2 ;
 _MATELM1( 5 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ C3 <-> C2 ( Rb3 , Ru3 )*/
 f_flux =  Rb3 * C3 ;
 b_flux =  Ru3 * C2 ;
 _RHS1( 4) -= (f_flux - b_flux);
 _RHS1( 3) += (f_flux - b_flux);
 
 _term =  Rb3 ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  Ru3 ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ C2 <-> C1 ( Rb4 , Ru4 )*/
 f_flux =  Rb4 * C2 ;
 b_flux =  Ru4 * C1 ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 2) += (f_flux - b_flux);
 
 _term =  Rb4 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  Ru4 ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ C1 <-> C0 ( Rb5 , Ru5 )*/
 f_flux =  Rb5 * C1 ;
 b_flux =  Ru5 * C0 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 
 _term =  Rb5 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  Ru5 ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ C4 <-> O1 ( Ro1 , Rc1 )*/
 f_flux =  Ro1 * C4 ;
 b_flux =  Rc1 * O1 ;
 _RHS1( 5) -= (f_flux - b_flux);
 _RHS1( 17) += (f_flux - b_flux);
 
 _term =  Ro1 ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 17 ,5)  -= _term;
 _term =  Rc1 ;
 _MATELM1( 5 ,17)  -= _term;
 _MATELM1( 17 ,17)  += _term;
 /*REACTION*/
  /* ~ C3 <-> O2 ( Ro2 , Rc2 )*/
 f_flux =  Ro2 * C3 ;
 b_flux =  Rc2 * O2 ;
 _RHS1( 4) -= (f_flux - b_flux);
 _RHS1( 16) += (f_flux - b_flux);
 
 _term =  Ro2 ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 16 ,4)  -= _term;
 _term =  Rc2 ;
 _MATELM1( 4 ,16)  -= _term;
 _MATELM1( 16 ,16)  += _term;
 /*REACTION*/
  /* ~ C2 <-> O3 ( Ro3 , Rc3 )*/
 f_flux =  Ro3 * C2 ;
 b_flux =  Rc3 * O3 ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 15) += (f_flux - b_flux);
 
 _term =  Ro3 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 15 ,3)  -= _term;
 _term =  Rc3 ;
 _MATELM1( 3 ,15)  -= _term;
 _MATELM1( 15 ,15)  += _term;
 /*REACTION*/
  /* ~ C1 <-> O4 ( Ro4 , Rc4 )*/
 f_flux =  Ro4 * C1 ;
 b_flux =  Rc4 * O4 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 14) += (f_flux - b_flux);
 
 _term =  Ro4 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 14 ,2)  -= _term;
 _term =  Rc4 ;
 _MATELM1( 2 ,14)  -= _term;
 _MATELM1( 14 ,14)  += _term;
 /*REACTION*/
  /* ~ C0 <-> O5 ( Ro5 , Rc5 )*/
 f_flux =  Ro5 * C0 ;
 b_flux =  Rc5 * O5 ;
 _RHS1( 1) -= (f_flux - b_flux);
 _RHS1( 13) += (f_flux - b_flux);
 
 _term =  Ro5 ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 13 ,1)  -= _term;
 _term =  Rc5 ;
 _MATELM1( 1 ,13)  -= _term;
 _MATELM1( 13 ,13)  += _term;
 /*REACTION*/
  /* ~ C5 <-> D0 ( Rd0 , Rr0 )*/
 f_flux =  Rd0 * C5 ;
 b_flux =  Rr0 * D0 ;
 _RHS1( 6) -= (f_flux - b_flux);
 _RHS1( 12) += (f_flux - b_flux);
 
 _term =  Rd0 ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 12 ,6)  -= _term;
 _term =  Rr0 ;
 _MATELM1( 6 ,12)  -= _term;
 _MATELM1( 12 ,12)  += _term;
 /*REACTION*/
  /* ~ C4 <-> D1 ( Rd1 , Rr1 )*/
 f_flux =  Rd1 * C4 ;
 b_flux =  Rr1 * D1 ;
 _RHS1( 5) -= (f_flux - b_flux);
 _RHS1( 11) += (f_flux - b_flux);
 
 _term =  Rd1 ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 11 ,5)  -= _term;
 _term =  Rr1 ;
 _MATELM1( 5 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ C3 <-> D2 ( Rd2 , Rr2 )*/
 f_flux =  Rd2 * C3 ;
 b_flux =  Rr2 * D2 ;
 _RHS1( 4) -= (f_flux - b_flux);
 _RHS1( 10) += (f_flux - b_flux);
 
 _term =  Rd2 ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 10 ,4)  -= _term;
 _term =  Rr2 ;
 _MATELM1( 4 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ C2 <-> D3 ( Rd3 , Rr3 )*/
 f_flux =  Rd3 * C2 ;
 b_flux =  Rr3 * D3 ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 9) += (f_flux - b_flux);
 
 _term =  Rd3 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 9 ,3)  -= _term;
 _term =  Rr3 ;
 _MATELM1( 3 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ C1 <-> D4 ( Rd4 , Rr4 )*/
 f_flux =  Rd4 * C1 ;
 b_flux =  Rr4 * D4 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 8) += (f_flux - b_flux);
 
 _term =  Rd4 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 8 ,2)  -= _term;
 _term =  Rr4 ;
 _MATELM1( 2 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ C0 <-> D5 ( Rd5 , Rr5 )*/
 f_flux =  Rd5 * C0 ;
 b_flux =  Rr5 * D5 ;
 _RHS1( 1) -= (f_flux - b_flux);
 _RHS1( 7) += (f_flux - b_flux);
 
 _term =  Rd5 ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 7 ,1)  -= _term;
 _term =  Rr5 ;
 _MATELM1( 1 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ D0 <-> D1 ( Rb1 , Rd1d0 )*/
 f_flux =  Rb1 * D0 ;
 b_flux =  Rd1d0 * D1 ;
 _RHS1( 12) -= (f_flux - b_flux);
 _RHS1( 11) += (f_flux - b_flux);
 
 _term =  Rb1 ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 11 ,12)  -= _term;
 _term =  Rd1d0 ;
 _MATELM1( 12 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ D1 <-> D2 ( Rb2 , Rd2d1 )*/
 f_flux =  Rb2 * D1 ;
 b_flux =  Rd2d1 * D2 ;
 _RHS1( 11) -= (f_flux - b_flux);
 _RHS1( 10) += (f_flux - b_flux);
 
 _term =  Rb2 ;
 _MATELM1( 11 ,11)  += _term;
 _MATELM1( 10 ,11)  -= _term;
 _term =  Rd2d1 ;
 _MATELM1( 11 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ D2 <-> D3 ( Rb1 , Rd3d2 )*/
 f_flux =  Rb1 * D2 ;
 b_flux =  Rd3d2 * D3 ;
 _RHS1( 10) -= (f_flux - b_flux);
 _RHS1( 9) += (f_flux - b_flux);
 
 _term =  Rb1 ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 9 ,10)  -= _term;
 _term =  Rd3d2 ;
 _MATELM1( 10 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ D0 <-> D1 ( Rb1 , Rd4d3 )*/
 f_flux =  Rb1 * D0 ;
 b_flux =  Rd4d3 * D1 ;
 _RHS1( 12) -= (f_flux - b_flux);
 _RHS1( 11) += (f_flux - b_flux);
 
 _term =  Rb1 ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 11 ,12)  -= _term;
 _term =  Rd4d3 ;
 _MATELM1( 12 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ D0 <-> D1 ( Rb1 , Rd5d4 )*/
 f_flux =  Rb1 * D0 ;
 b_flux =  Rd5d4 * D1 ;
 _RHS1( 12) -= (f_flux - b_flux);
 _RHS1( 11) += (f_flux - b_flux);
 
 _term =  Rb1 ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 11 ,12)  -= _term;
 _term =  Rd5d4 ;
 _MATELM1( 12 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ D0 <-> SD0 ( Rsd0 , Rrsd0 )*/
 f_flux =  Rsd0 * D0 ;
 b_flux =  Rrsd0 * SD0 ;
 _RHS1( 12) -= (f_flux - b_flux);
 _RHS1( 22) += (f_flux - b_flux);
 
 _term =  Rsd0 ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 22 ,12)  -= _term;
 _term =  Rrsd0 ;
 _MATELM1( 12 ,22)  -= _term;
 _MATELM1( 22 ,22)  += _term;
 /*REACTION*/
  /* ~ D1 <-> SD1 ( Rsd1 , Rrsd1 )*/
 f_flux =  Rsd1 * D1 ;
 b_flux =  Rrsd1 * SD1 ;
 _RHS1( 11) -= (f_flux - b_flux);
 _RHS1( 21) += (f_flux - b_flux);
 
 _term =  Rsd1 ;
 _MATELM1( 11 ,11)  += _term;
 _MATELM1( 21 ,11)  -= _term;
 _term =  Rrsd1 ;
 _MATELM1( 11 ,21)  -= _term;
 _MATELM1( 21 ,21)  += _term;
 /*REACTION*/
  /* ~ D2 <-> SD2 ( Rsd2 , Rrsd2 )*/
 f_flux =  Rsd2 * D2 ;
 b_flux =  Rrsd2 * SD2 ;
 _RHS1( 10) -= (f_flux - b_flux);
 _RHS1( 20) += (f_flux - b_flux);
 
 _term =  Rsd2 ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 20 ,10)  -= _term;
 _term =  Rrsd2 ;
 _MATELM1( 10 ,20)  -= _term;
 _MATELM1( 20 ,20)  += _term;
 /*REACTION*/
  /* ~ D3 <-> SD3 ( Rsd3 , Rrsd3 )*/
 f_flux =  Rsd3 * D3 ;
 b_flux =  Rrsd3 * SD3 ;
 _RHS1( 9) -= (f_flux - b_flux);
 _RHS1( 19) += (f_flux - b_flux);
 
 _term =  Rsd3 ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 19 ,9)  -= _term;
 _term =  Rrsd3 ;
 _MATELM1( 9 ,19)  -= _term;
 _MATELM1( 19 ,19)  += _term;
 /*REACTION*/
  /* ~ D4 <-> SD4 ( Rsd4 , Rrsd4 )*/
 f_flux =  Rsd4 * D4 ;
 b_flux =  Rrsd4 * SD4 ;
 _RHS1( 8) -= (f_flux - b_flux);
 _RHS1( 18) += (f_flux - b_flux);
 
 _term =  Rsd4 ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 18 ,8)  -= _term;
 _term =  Rrsd4 ;
 _MATELM1( 8 ,18)  -= _term;
 _MATELM1( 18 ,18)  += _term;
 /*REACTION*/
  /* ~ D5 <-> SD5 ( Rsd5 , Rrsd5 )*/
 f_flux =  Rsd5 * D5 ;
 b_flux =  Rrsd5 * SD5 ;
 _RHS1( 7) -= (f_flux - b_flux);
 
 _term =  Rsd5 ;
 _MATELM1( 7 ,7)  += _term;
 _term =  Rrsd5 ;
 _MATELM1( 7 ,0)  -= _term;
 /*REACTION*/
  /* ~ SD0 <-> SD1 ( Rb1 , Rsd1sd0 )*/
 f_flux =  Rb1 * SD0 ;
 b_flux =  Rsd1sd0 * SD1 ;
 _RHS1( 22) -= (f_flux - b_flux);
 _RHS1( 21) += (f_flux - b_flux);
 
 _term =  Rb1 ;
 _MATELM1( 22 ,22)  += _term;
 _MATELM1( 21 ,22)  -= _term;
 _term =  Rsd1sd0 ;
 _MATELM1( 22 ,21)  -= _term;
 _MATELM1( 21 ,21)  += _term;
 /*REACTION*/
  /* ~ SD1 <-> SD2 ( Rb2 , Rsd2sd1 )*/
 f_flux =  Rb2 * SD1 ;
 b_flux =  Rsd2sd1 * SD2 ;
 _RHS1( 21) -= (f_flux - b_flux);
 _RHS1( 20) += (f_flux - b_flux);
 
 _term =  Rb2 ;
 _MATELM1( 21 ,21)  += _term;
 _MATELM1( 20 ,21)  -= _term;
 _term =  Rsd2sd1 ;
 _MATELM1( 21 ,20)  -= _term;
 _MATELM1( 20 ,20)  += _term;
 /*REACTION*/
  /* ~ SD2 <-> SD3 ( Rb3 , Rsd3sd2 )*/
 f_flux =  Rb3 * SD2 ;
 b_flux =  Rsd3sd2 * SD3 ;
 _RHS1( 20) -= (f_flux - b_flux);
 _RHS1( 19) += (f_flux - b_flux);
 
 _term =  Rb3 ;
 _MATELM1( 20 ,20)  += _term;
 _MATELM1( 19 ,20)  -= _term;
 _term =  Rsd3sd2 ;
 _MATELM1( 20 ,19)  -= _term;
 _MATELM1( 19 ,19)  += _term;
 /*REACTION*/
  /* ~ SD3 <-> SD4 ( Rb4 , Rsd4sd3 )*/
 f_flux =  Rb4 * SD3 ;
 b_flux =  Rsd4sd3 * SD4 ;
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 18) += (f_flux - b_flux);
 
 _term =  Rb4 ;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 18 ,19)  -= _term;
 _term =  Rsd4sd3 ;
 _MATELM1( 19 ,18)  -= _term;
 _MATELM1( 18 ,18)  += _term;
 /*REACTION*/
  /* ~ SD4 <-> SD5 ( Rb5 , Rsd5sd4 )*/
 f_flux =  Rb5 * SD4 ;
 b_flux =  Rsd5sd4 * SD5 ;
 _RHS1( 18) -= (f_flux - b_flux);
 
 _term =  Rb5 ;
 _MATELM1( 18 ,18)  += _term;
 _term =  Rsd5sd4 ;
 _MATELM1( 18 ,0)  -= _term;
 /*REACTION*/
   /* C5 + C4 + C3 + C2 + C1 + C0 + O1 + O2 + O3 + O4 + O5 + D0 + D1 + D2 + D3 + D4 + D5 + SD0 + SD1 + SD2 + SD3 + SD4 + SD5 = 1.0 */
 _RHS1(0) =  1.0;
 _MATELM1(0, 0) = 1;
 _RHS1(0) -= SD5 ;
 _MATELM1(0, 18) = 1;
 _RHS1(0) -= SD4 ;
 _MATELM1(0, 19) = 1;
 _RHS1(0) -= SD3 ;
 _MATELM1(0, 20) = 1;
 _RHS1(0) -= SD2 ;
 _MATELM1(0, 21) = 1;
 _RHS1(0) -= SD1 ;
 _MATELM1(0, 22) = 1;
 _RHS1(0) -= SD0 ;
 _MATELM1(0, 7) = 1;
 _RHS1(0) -= D5 ;
 _MATELM1(0, 8) = 1;
 _RHS1(0) -= D4 ;
 _MATELM1(0, 9) = 1;
 _RHS1(0) -= D3 ;
 _MATELM1(0, 10) = 1;
 _RHS1(0) -= D2 ;
 _MATELM1(0, 11) = 1;
 _RHS1(0) -= D1 ;
 _MATELM1(0, 12) = 1;
 _RHS1(0) -= D0 ;
 _MATELM1(0, 13) = 1;
 _RHS1(0) -= O5 ;
 _MATELM1(0, 14) = 1;
 _RHS1(0) -= O4 ;
 _MATELM1(0, 15) = 1;
 _RHS1(0) -= O3 ;
 _MATELM1(0, 16) = 1;
 _RHS1(0) -= O2 ;
 _MATELM1(0, 17) = 1;
 _RHS1(0) -= O1 ;
 _MATELM1(0, 1) = 1;
 _RHS1(0) -= C0 ;
 _MATELM1(0, 2) = 1;
 _RHS1(0) -= C1 ;
 _MATELM1(0, 3) = 1;
 _RHS1(0) -= C2 ;
 _MATELM1(0, 4) = 1;
 _RHS1(0) -= C3 ;
 _MATELM1(0, 5) = 1;
 _RHS1(0) -= C4 ;
 _MATELM1(0, 6) = 1;
 _RHS1(0) -= C5 ;
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE ode begin*/
 static int _ode_spec1() {_reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<23;_i++) _p[_dlist1[_i]] = 0.0;}
 Rb1 = rb1 * C ;
 Rb2 = rb2 * C ;
 Rb3 = rb3 * C ;
 Rb4 = rb4 * C ;
 Rb5 = rb5 * C ;
 /* ~ C5 <-> C4 ( Rb1 , Ru1 )*/
 f_flux =  Rb1 * C5 ;
 b_flux =  Ru1 * C4 ;
 DC5 -= (f_flux - b_flux);
 DC4 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C4 <-> C3 ( Rb2 , Ru2 )*/
 f_flux =  Rb2 * C4 ;
 b_flux =  Ru2 * C3 ;
 DC4 -= (f_flux - b_flux);
 DC3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C3 <-> C2 ( Rb3 , Ru3 )*/
 f_flux =  Rb3 * C3 ;
 b_flux =  Ru3 * C2 ;
 DC3 -= (f_flux - b_flux);
 DC2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C2 <-> C1 ( Rb4 , Ru4 )*/
 f_flux =  Rb4 * C2 ;
 b_flux =  Ru4 * C1 ;
 DC2 -= (f_flux - b_flux);
 DC1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C1 <-> C0 ( Rb5 , Ru5 )*/
 f_flux =  Rb5 * C1 ;
 b_flux =  Ru5 * C0 ;
 DC1 -= (f_flux - b_flux);
 DC0 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C4 <-> O1 ( Ro1 , Rc1 )*/
 f_flux =  Ro1 * C4 ;
 b_flux =  Rc1 * O1 ;
 DC4 -= (f_flux - b_flux);
 DO1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C3 <-> O2 ( Ro2 , Rc2 )*/
 f_flux =  Ro2 * C3 ;
 b_flux =  Rc2 * O2 ;
 DC3 -= (f_flux - b_flux);
 DO2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C2 <-> O3 ( Ro3 , Rc3 )*/
 f_flux =  Ro3 * C2 ;
 b_flux =  Rc3 * O3 ;
 DC2 -= (f_flux - b_flux);
 DO3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C1 <-> O4 ( Ro4 , Rc4 )*/
 f_flux =  Ro4 * C1 ;
 b_flux =  Rc4 * O4 ;
 DC1 -= (f_flux - b_flux);
 DO4 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C0 <-> O5 ( Ro5 , Rc5 )*/
 f_flux =  Ro5 * C0 ;
 b_flux =  Rc5 * O5 ;
 DC0 -= (f_flux - b_flux);
 DO5 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C5 <-> D0 ( Rd0 , Rr0 )*/
 f_flux =  Rd0 * C5 ;
 b_flux =  Rr0 * D0 ;
 DC5 -= (f_flux - b_flux);
 DD0 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C4 <-> D1 ( Rd1 , Rr1 )*/
 f_flux =  Rd1 * C4 ;
 b_flux =  Rr1 * D1 ;
 DC4 -= (f_flux - b_flux);
 DD1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C3 <-> D2 ( Rd2 , Rr2 )*/
 f_flux =  Rd2 * C3 ;
 b_flux =  Rr2 * D2 ;
 DC3 -= (f_flux - b_flux);
 DD2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C2 <-> D3 ( Rd3 , Rr3 )*/
 f_flux =  Rd3 * C2 ;
 b_flux =  Rr3 * D3 ;
 DC2 -= (f_flux - b_flux);
 DD3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C1 <-> D4 ( Rd4 , Rr4 )*/
 f_flux =  Rd4 * C1 ;
 b_flux =  Rr4 * D4 ;
 DC1 -= (f_flux - b_flux);
 DD4 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C0 <-> D5 ( Rd5 , Rr5 )*/
 f_flux =  Rd5 * C0 ;
 b_flux =  Rr5 * D5 ;
 DC0 -= (f_flux - b_flux);
 DD5 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ D0 <-> D1 ( Rb1 , Rd1d0 )*/
 f_flux =  Rb1 * D0 ;
 b_flux =  Rd1d0 * D1 ;
 DD0 -= (f_flux - b_flux);
 DD1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ D1 <-> D2 ( Rb2 , Rd2d1 )*/
 f_flux =  Rb2 * D1 ;
 b_flux =  Rd2d1 * D2 ;
 DD1 -= (f_flux - b_flux);
 DD2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ D2 <-> D3 ( Rb1 , Rd3d2 )*/
 f_flux =  Rb1 * D2 ;
 b_flux =  Rd3d2 * D3 ;
 DD2 -= (f_flux - b_flux);
 DD3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ D0 <-> D1 ( Rb1 , Rd4d3 )*/
 f_flux =  Rb1 * D0 ;
 b_flux =  Rd4d3 * D1 ;
 DD0 -= (f_flux - b_flux);
 DD1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ D0 <-> D1 ( Rb1 , Rd5d4 )*/
 f_flux =  Rb1 * D0 ;
 b_flux =  Rd5d4 * D1 ;
 DD0 -= (f_flux - b_flux);
 DD1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ D0 <-> SD0 ( Rsd0 , Rrsd0 )*/
 f_flux =  Rsd0 * D0 ;
 b_flux =  Rrsd0 * SD0 ;
 DD0 -= (f_flux - b_flux);
 DSD0 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ D1 <-> SD1 ( Rsd1 , Rrsd1 )*/
 f_flux =  Rsd1 * D1 ;
 b_flux =  Rrsd1 * SD1 ;
 DD1 -= (f_flux - b_flux);
 DSD1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ D2 <-> SD2 ( Rsd2 , Rrsd2 )*/
 f_flux =  Rsd2 * D2 ;
 b_flux =  Rrsd2 * SD2 ;
 DD2 -= (f_flux - b_flux);
 DSD2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ D3 <-> SD3 ( Rsd3 , Rrsd3 )*/
 f_flux =  Rsd3 * D3 ;
 b_flux =  Rrsd3 * SD3 ;
 DD3 -= (f_flux - b_flux);
 DSD3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ D4 <-> SD4 ( Rsd4 , Rrsd4 )*/
 f_flux =  Rsd4 * D4 ;
 b_flux =  Rrsd4 * SD4 ;
 DD4 -= (f_flux - b_flux);
 DSD4 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ D5 <-> SD5 ( Rsd5 , Rrsd5 )*/
 f_flux =  Rsd5 * D5 ;
 b_flux =  Rrsd5 * SD5 ;
 DD5 -= (f_flux - b_flux);
 DSD5 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ SD0 <-> SD1 ( Rb1 , Rsd1sd0 )*/
 f_flux =  Rb1 * SD0 ;
 b_flux =  Rsd1sd0 * SD1 ;
 DSD0 -= (f_flux - b_flux);
 DSD1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ SD1 <-> SD2 ( Rb2 , Rsd2sd1 )*/
 f_flux =  Rb2 * SD1 ;
 b_flux =  Rsd2sd1 * SD2 ;
 DSD1 -= (f_flux - b_flux);
 DSD2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ SD2 <-> SD3 ( Rb3 , Rsd3sd2 )*/
 f_flux =  Rb3 * SD2 ;
 b_flux =  Rsd3sd2 * SD3 ;
 DSD2 -= (f_flux - b_flux);
 DSD3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ SD3 <-> SD4 ( Rb4 , Rsd4sd3 )*/
 f_flux =  Rb4 * SD3 ;
 b_flux =  Rsd4sd3 * SD4 ;
 DSD3 -= (f_flux - b_flux);
 DSD4 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ SD4 <-> SD5 ( Rb5 , Rsd5sd4 )*/
 f_flux =  Rb5 * SD4 ;
 b_flux =  Rsd5sd4 * SD5 ;
 DSD4 -= (f_flux - b_flux);
 DSD5 += (f_flux - b_flux);
 
 /*REACTION*/
   /* C5 + C4 + C3 + C2 + C1 + C0 + O1 + O2 + O3 + O4 + O5 + D0 + D1 + D2 + D3 + D4 + D5 + SD0 + SD1 + SD2 + SD3 + SD4 + SD5 = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1() {_reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<23;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 Rb1 = rb1 * C ;
 Rb2 = rb2 * C ;
 Rb3 = rb3 * C ;
 Rb4 = rb4 * C ;
 Rb5 = rb5 * C ;
 /* ~ C5 <-> C4 ( Rb1 , Ru1 )*/
 _term =  Rb1 ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 5 ,6)  -= _term;
 _term =  Ru1 ;
 _MATELM1( 6 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ C4 <-> C3 ( Rb2 , Ru2 )*/
 _term =  Rb2 ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 4 ,5)  -= _term;
 _term =  Ru2 ;
 _MATELM1( 5 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ C3 <-> C2 ( Rb3 , Ru3 )*/
 _term =  Rb3 ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  Ru3 ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ C2 <-> C1 ( Rb4 , Ru4 )*/
 _term =  Rb4 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  Ru4 ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ C1 <-> C0 ( Rb5 , Ru5 )*/
 _term =  Rb5 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  Ru5 ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ C4 <-> O1 ( Ro1 , Rc1 )*/
 _term =  Ro1 ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 17 ,5)  -= _term;
 _term =  Rc1 ;
 _MATELM1( 5 ,17)  -= _term;
 _MATELM1( 17 ,17)  += _term;
 /*REACTION*/
  /* ~ C3 <-> O2 ( Ro2 , Rc2 )*/
 _term =  Ro2 ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 16 ,4)  -= _term;
 _term =  Rc2 ;
 _MATELM1( 4 ,16)  -= _term;
 _MATELM1( 16 ,16)  += _term;
 /*REACTION*/
  /* ~ C2 <-> O3 ( Ro3 , Rc3 )*/
 _term =  Ro3 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 15 ,3)  -= _term;
 _term =  Rc3 ;
 _MATELM1( 3 ,15)  -= _term;
 _MATELM1( 15 ,15)  += _term;
 /*REACTION*/
  /* ~ C1 <-> O4 ( Ro4 , Rc4 )*/
 _term =  Ro4 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 14 ,2)  -= _term;
 _term =  Rc4 ;
 _MATELM1( 2 ,14)  -= _term;
 _MATELM1( 14 ,14)  += _term;
 /*REACTION*/
  /* ~ C0 <-> O5 ( Ro5 , Rc5 )*/
 _term =  Ro5 ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 13 ,1)  -= _term;
 _term =  Rc5 ;
 _MATELM1( 1 ,13)  -= _term;
 _MATELM1( 13 ,13)  += _term;
 /*REACTION*/
  /* ~ C5 <-> D0 ( Rd0 , Rr0 )*/
 _term =  Rd0 ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 12 ,6)  -= _term;
 _term =  Rr0 ;
 _MATELM1( 6 ,12)  -= _term;
 _MATELM1( 12 ,12)  += _term;
 /*REACTION*/
  /* ~ C4 <-> D1 ( Rd1 , Rr1 )*/
 _term =  Rd1 ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 11 ,5)  -= _term;
 _term =  Rr1 ;
 _MATELM1( 5 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ C3 <-> D2 ( Rd2 , Rr2 )*/
 _term =  Rd2 ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 10 ,4)  -= _term;
 _term =  Rr2 ;
 _MATELM1( 4 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ C2 <-> D3 ( Rd3 , Rr3 )*/
 _term =  Rd3 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 9 ,3)  -= _term;
 _term =  Rr3 ;
 _MATELM1( 3 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ C1 <-> D4 ( Rd4 , Rr4 )*/
 _term =  Rd4 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 8 ,2)  -= _term;
 _term =  Rr4 ;
 _MATELM1( 2 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ C0 <-> D5 ( Rd5 , Rr5 )*/
 _term =  Rd5 ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 7 ,1)  -= _term;
 _term =  Rr5 ;
 _MATELM1( 1 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ D0 <-> D1 ( Rb1 , Rd1d0 )*/
 _term =  Rb1 ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 11 ,12)  -= _term;
 _term =  Rd1d0 ;
 _MATELM1( 12 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ D1 <-> D2 ( Rb2 , Rd2d1 )*/
 _term =  Rb2 ;
 _MATELM1( 11 ,11)  += _term;
 _MATELM1( 10 ,11)  -= _term;
 _term =  Rd2d1 ;
 _MATELM1( 11 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ D2 <-> D3 ( Rb1 , Rd3d2 )*/
 _term =  Rb1 ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 9 ,10)  -= _term;
 _term =  Rd3d2 ;
 _MATELM1( 10 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ D0 <-> D1 ( Rb1 , Rd4d3 )*/
 _term =  Rb1 ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 11 ,12)  -= _term;
 _term =  Rd4d3 ;
 _MATELM1( 12 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ D0 <-> D1 ( Rb1 , Rd5d4 )*/
 _term =  Rb1 ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 11 ,12)  -= _term;
 _term =  Rd5d4 ;
 _MATELM1( 12 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ D0 <-> SD0 ( Rsd0 , Rrsd0 )*/
 _term =  Rsd0 ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 22 ,12)  -= _term;
 _term =  Rrsd0 ;
 _MATELM1( 12 ,22)  -= _term;
 _MATELM1( 22 ,22)  += _term;
 /*REACTION*/
  /* ~ D1 <-> SD1 ( Rsd1 , Rrsd1 )*/
 _term =  Rsd1 ;
 _MATELM1( 11 ,11)  += _term;
 _MATELM1( 21 ,11)  -= _term;
 _term =  Rrsd1 ;
 _MATELM1( 11 ,21)  -= _term;
 _MATELM1( 21 ,21)  += _term;
 /*REACTION*/
  /* ~ D2 <-> SD2 ( Rsd2 , Rrsd2 )*/
 _term =  Rsd2 ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 20 ,10)  -= _term;
 _term =  Rrsd2 ;
 _MATELM1( 10 ,20)  -= _term;
 _MATELM1( 20 ,20)  += _term;
 /*REACTION*/
  /* ~ D3 <-> SD3 ( Rsd3 , Rrsd3 )*/
 _term =  Rsd3 ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 19 ,9)  -= _term;
 _term =  Rrsd3 ;
 _MATELM1( 9 ,19)  -= _term;
 _MATELM1( 19 ,19)  += _term;
 /*REACTION*/
  /* ~ D4 <-> SD4 ( Rsd4 , Rrsd4 )*/
 _term =  Rsd4 ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 18 ,8)  -= _term;
 _term =  Rrsd4 ;
 _MATELM1( 8 ,18)  -= _term;
 _MATELM1( 18 ,18)  += _term;
 /*REACTION*/
  /* ~ D5 <-> SD5 ( Rsd5 , Rrsd5 )*/
 _term =  Rsd5 ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 0 ,7)  -= _term;
 _term =  Rrsd5 ;
 _MATELM1( 7 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ SD0 <-> SD1 ( Rb1 , Rsd1sd0 )*/
 _term =  Rb1 ;
 _MATELM1( 22 ,22)  += _term;
 _MATELM1( 21 ,22)  -= _term;
 _term =  Rsd1sd0 ;
 _MATELM1( 22 ,21)  -= _term;
 _MATELM1( 21 ,21)  += _term;
 /*REACTION*/
  /* ~ SD1 <-> SD2 ( Rb2 , Rsd2sd1 )*/
 _term =  Rb2 ;
 _MATELM1( 21 ,21)  += _term;
 _MATELM1( 20 ,21)  -= _term;
 _term =  Rsd2sd1 ;
 _MATELM1( 21 ,20)  -= _term;
 _MATELM1( 20 ,20)  += _term;
 /*REACTION*/
  /* ~ SD2 <-> SD3 ( Rb3 , Rsd3sd2 )*/
 _term =  Rb3 ;
 _MATELM1( 20 ,20)  += _term;
 _MATELM1( 19 ,20)  -= _term;
 _term =  Rsd3sd2 ;
 _MATELM1( 20 ,19)  -= _term;
 _MATELM1( 19 ,19)  += _term;
 /*REACTION*/
  /* ~ SD3 <-> SD4 ( Rb4 , Rsd4sd3 )*/
 _term =  Rb4 ;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 18 ,19)  -= _term;
 _term =  Rsd4sd3 ;
 _MATELM1( 19 ,18)  -= _term;
 _MATELM1( 18 ,18)  += _term;
 /*REACTION*/
  /* ~ SD4 <-> SD5 ( Rb5 , Rsd5sd4 )*/
 _term =  Rb5 ;
 _MATELM1( 18 ,18)  += _term;
 _MATELM1( 0 ,18)  -= _term;
 _term =  Rsd5sd4 ;
 _MATELM1( 18 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
   /* C5 + C4 + C3 + C2 + C1 + C0 + O1 + O2 + O3 + O4 + O5 + D0 + D1 + D2 + D3 + D4 + D5 + SD0 + SD1 + SD2 + SD3 + SD4 + SD5 = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 23;}
 
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
	for (_i=0; _i < 23; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _cvode_sparse(&_cvsparseobj1, 23, _dlist1, _p, _ode_matsol1, &_coef1);
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
  C0 = C00;
  C1 = C10;
  C2 = C20;
  C3 = C30;
  C4 = C40;
  C5 = C50;
  D5 = D50;
  D4 = D40;
  D3 = D30;
  D2 = D20;
  D1 = D10;
  D0 = D00;
  O5 = O50;
  O4 = O40;
  O3 = O30;
  O2 = O20;
  O1 = O10;
  SD5 = SD50;
  SD4 = SD40;
  SD3 = SD30;
  SD2 = SD20;
  SD1 = SD10;
  SD0 = SD00;
 {
   C5 = 1.0 ;
   C4 = 0.0 ;
   C3 = 0.0 ;
   C2 = 0.0 ;
   C1 = 0.0 ;
   C0 = 0.0 ;
   O1 = 0.0 ;
   O2 = 0.0 ;
   O3 = 0.0 ;
   O4 = 0.0 ;
   O5 = 0.0 ;
   D0 = 0.0 ;
   D1 = 0.0 ;
   D2 = 0.0 ;
   D3 = 0.0 ;
   D4 = 0.0 ;
   D5 = 0.0 ;
   SD0 = 0.0 ;
   SD1 = 0.0 ;
   SD2 = 0.0 ;
   SD3 = 0.0 ;
   SD4 = 0.0 ;
   SD5 = 0.0 ;
   tr = 0.0 ;
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
   g = gmax * ( O1 + O2 + O3 + O4 + O5 ) ;
   curr = ( 1e-6 ) * g * ( v - Erev ) ;
   ica = 0.77 * curr ;
   ina = 0.115 * curr ;
   ik = 0.115 * curr ;
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
 { error = sparse(&_sparseobj1, 23, _slist1, _dlist1, _p, &t, dt, kstates,&_coef1, _linmat1);
 if(error){fprintf(stderr,"at line 151 in file a7.mod:\n\n"); nrn_complain(_p); abort_run(error);}
    if (secondorder) {
    int _i;
    for (_i = 0; _i < 23; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 }   }}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = SD5_columnindex;  _dlist1[0] = DSD5_columnindex;
 _slist1[1] = C0_columnindex;  _dlist1[1] = DC0_columnindex;
 _slist1[2] = C1_columnindex;  _dlist1[2] = DC1_columnindex;
 _slist1[3] = C2_columnindex;  _dlist1[3] = DC2_columnindex;
 _slist1[4] = C3_columnindex;  _dlist1[4] = DC3_columnindex;
 _slist1[5] = C4_columnindex;  _dlist1[5] = DC4_columnindex;
 _slist1[6] = C5_columnindex;  _dlist1[6] = DC5_columnindex;
 _slist1[7] = D5_columnindex;  _dlist1[7] = DD5_columnindex;
 _slist1[8] = D4_columnindex;  _dlist1[8] = DD4_columnindex;
 _slist1[9] = D3_columnindex;  _dlist1[9] = DD3_columnindex;
 _slist1[10] = D2_columnindex;  _dlist1[10] = DD2_columnindex;
 _slist1[11] = D1_columnindex;  _dlist1[11] = DD1_columnindex;
 _slist1[12] = D0_columnindex;  _dlist1[12] = DD0_columnindex;
 _slist1[13] = O5_columnindex;  _dlist1[13] = DO5_columnindex;
 _slist1[14] = O4_columnindex;  _dlist1[14] = DO4_columnindex;
 _slist1[15] = O3_columnindex;  _dlist1[15] = DO3_columnindex;
 _slist1[16] = O2_columnindex;  _dlist1[16] = DO2_columnindex;
 _slist1[17] = O1_columnindex;  _dlist1[17] = DO1_columnindex;
 _slist1[18] = SD4_columnindex;  _dlist1[18] = DSD4_columnindex;
 _slist1[19] = SD3_columnindex;  _dlist1[19] = DSD3_columnindex;
 _slist1[20] = SD2_columnindex;  _dlist1[20] = DSD2_columnindex;
 _slist1[21] = SD1_columnindex;  _dlist1[21] = DSD1_columnindex;
 _slist1[22] = SD0_columnindex;  _dlist1[22] = DSD0_columnindex;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "a7.mod";
static const char* nmodl_file_text = 
  "NEURON {\n"
  "  POINT_PROCESS a7\n"
  "  USEION na WRITE ina\n"
  "  USEION ca WRITE ica\n"
  "  USEION k WRITE ik\n"
  "  POINTER C\n"
  "  RANGE curr, ica, ina, ik\n"
  "  RANGE  O1, O2, O3, O4, O5, C5, C4, C3, C2, C1, C0, D0, D1, D2, D3, D4, D5, SD0, SD1, SD2, SD3, SD4, SD5\n"
  "  RANGE g, gmax, del, tdur\n"
  "  GLOBAL Erev\n"
  "  GLOBAL rb1, rb2, rb3, rb4, rb5, Ru1, Ru2, Ru3,Ru4, Ru5, Ro1, Ro2, Ro3, Ro4, Ro5, Rc1, Rc2, Rc3, Rc4, Rc5\n"
  "  GLOBAL Rd0, Rd1, Rd2, Rd3, Rd4, Rd5, Rr0, Rr1, Rr2, Rr3, Rr4, Rr5, Rd1d0, Rd2d1, Rd3d2, Rd4d3, Rd5d4\n"
  "  GLOBAL  Rrsd0, Rrsd1, Rrsd2, Rrsd3, Rrsd4, Rrsd5, Rsd0, Rsd1, Rsd2, Rsd3, Rsd4, Rsd5, Rsd1sd0, Rsd2sd1, Rsd3sd2, Rsd4sd3, Rsd5sd4\n"
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
  "  Erev	= 0   (mV)	: reversal potential\n"
  "  gmax	= 95  (pS)	: maximal conductance\n"
  "  tdur = 5 (ms)\n"
  "  del =  0 (ms)\n"
  "\n"
  ": Rates\n"
  "\n"
  "  rb1 = 0.05 (/mM /ms)\n"
  "  rb2 = 0.04 (/mM /ms)\n"
  "  rb3 = 0.03 (/mM /ms)\n"
  "  rb4 = 0.02 (/mM /ms)\n"
  "  rb5 = 0.01 (/mM /ms)\n"
  "\n"
  "  Ru1 = 0.5 (/ms)\n"
  "  Ru2 = 10 (/ms)\n"
  "  Ru3 = 15 (/ms) \n"
  "  Ru4= 20 (/ms)\n"
  "  Ru5= 25(/ms)\n"
  "\n"
  "  Rd0 = 0.005 (/ms)\n"
  "  Rd1 = 0.025 (/ms)\n"
  "  Rd2 = 0.125 (/ms)\n"
  "  Rd3 = 0.625 (/ms)\n"
  "  Rd4 = 3.125 (/ms)\n"
  "  Rd5 = 15.625 (/ms)\n"
  "\n"
  "  Rr0 = 5 (/ms)\n"
  "  Rr1 = 1 (/ms)\n"
  "  Rr2 = 0.2 (/ms)\n"
  "  Rr3 = 0.04 (/ms)\n"
  "  Rr4 = 0.008 (/ms)  \n"
  "  Rr5 = 0.0016 (/ms)  \n"
  "\n"
  "  Ro1 = 5e-5 (/ms)\n"
  "  Ro2 = 1e-3 (/ms)\n"
  "  Ro3 = 0.02 (/ms)\n"
  "  Ro4 = 0.4 (/ms)\n"
  "  Ro5 = 8(/ms)\n"
  "\n"
  "  Rc1 = 0.02 (/ms)\n"
  "  Rc2 = 0.02 (/ms)\n"
  "  Rc3 = 0.02 (/ms)\n"
  "  Rc4 = 0.02 (/ms)\n"
  "  Rc5 = 0.02 (/ms)\n"
  "\n"
  "  Rd1d0 = 0.2 (/ms)\n"
  "  Rd2d1 = 0.4 (/ms)\n"
  "  Rd3d2 = 0.6 (/ms)\n"
  "  Rd4d3 = 0.8 (/ms)\n"
  "  Rd5d4 = 1 (/ms)\n"
  "\n"
  "  Rrsd0 = 1e-3 (/ms)\n"
  "  Rrsd1 = 5e-4 (/ms)\n"
  "  Rrsd2 = 2.5e-4 (/ms)\n"
  "  Rrsd3 = 1.25e-4 (/ms)\n"
  "  Rrsd4 = 6.25e-5 (/ms)\n"
  "  Rrsd5 = 3.125e-5 (/ms)\n"
  "\n"
  "  Rsd0 = 2e-5 (/ms)\n"
  "  Rsd1 = 4e-5 (/ms)\n"
  "  Rsd2 = 8e-5 (/ms)\n"
  "  Rsd3 = 16e-5 (/ms)\n"
  "  Rsd4 = 32e-5 (/ms)\n"
  "  Rsd5 = 64e-5 (/ms)\n"
  "\n"
  "  Rsd1sd0 = 0.05 (/ms)\n"
  "  Rsd2sd1 = 0.1 (/ms)\n"
  "  Rsd3sd2 = 0.15 (/ms)\n"
  "  Rsd4sd3 = 0.2 (/ms)\n"
  "  Rsd5sd4 = 0.25 (/ms)\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "  v		(mV)		: postsynaptic voltage\n"
  "  curr		(nA)		: current = g*(v - Erev)\n"
  "  g 		(pS)		: conductance\n"
  "  tr (mM)				:ACh conc\n"
  "  C (mM)				:pointer\n"
  "  Rb1		(/ms)    \n"
  "  Rb2		(/ms)    \n"
  "  Rb3		(/ms)    \n"
  "  Rb4		(/ms)    \n"
  "  Rb5		(/ms)    \n"
  "  ica (nA)\n"
  "  ina (nA)\n"
  "  ik (nA)\n"
  "}\n"
  "\n"
  "STATE {\n"
  "  C5 C4 C3 C2 C1 C0 \n"
  "  O1 O2 O3 O4 O5 \n"
  "  D0 D1 D2 D3 D4 D5 \n"
  "  SD0 SD1 SD2 SD3 SD4 SD5\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "  C5 =1\n"
  "  C4 =0\n"
  "  C3 =0 \n"
  "  C2 =0 \n"
  "  C1 =0 \n"
  "  C0 =0 \n"
  "  O1 =0 \n"
  "  O2 =0 \n"
  "  O3 =0 \n"
  "  O4 =0 \n"
  "  O5 =0 \n"
  "  D0 =0 \n"
  "  D1 =0 \n"
  "  D2 =0 \n"
  "  D3 =0 \n"
  "  D4 =0 \n"
  "  D5 =0 \n"
  "  SD0 =0 \n"
  "  SD1 =0 \n"
  "  SD2 =0 \n"
  "  SD3 =0 \n"
  "  SD4 =0 \n"
  "  SD5 =0 \n"
  "  tr = 0\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "  SOLVE kstates METHOD sparse\n"
  "\n"
  "  g = gmax * (O1 + O2 + O3 + O4 + O5)\n"
  "  curr = (1e-6) * g * (v - Erev)  \n"
  "  ica = 0.77*curr \n"
  "  ina = 0.115*curr\n"
  "  ik = 0.115*curr\n"
  "}\n"
  "\n"
  "KINETIC kstates {\n"
  "    Rb1 = rb1 * C\n"
  "    Rb2 = rb2 * C\n"
  "    Rb3 = rb3 * C\n"
  "    Rb4 = rb4 * C\n"
  "    Rb5 = rb5 * C\n"
  "    \n"
  "   ~ C5 <-> C4 (Rb1, Ru1 )\n"
  "   ~ C4 <-> C3 (Rb2, Ru2 )\n"
  "   ~ C3 <-> C2 (Rb3, Ru3 )\n"
  "   ~ C2 <-> C1 (Rb4, Ru4 )\n"
  "   ~ C1 <-> C0 (Rb5, Ru5 )\n"
  "\n"
  "   ~ C4 <-> O1 (Ro1, Rc1 )\n"
  "   ~ C3 <-> O2 (Ro2, Rc2 )\n"
  "   ~ C2 <-> O3 (Ro3, Rc3 )\n"
  "   ~ C1 <-> O4 (Ro4, Rc4 )\n"
  "   ~ C0 <-> O5 (Ro5, Rc5 )\n"
  "\n"
  "   ~ C5 <-> D0 (Rd0, Rr0 )\n"
  "   ~ C4 <-> D1 (Rd1, Rr1 )\n"
  "   ~ C3 <-> D2 (Rd2, Rr2 )\n"
  "   ~ C2 <-> D3 (Rd3, Rr3 )\n"
  "   ~ C1 <-> D4 (Rd4, Rr4 )\n"
  "   ~ C0 <-> D5 (Rd5, Rr5 )\n"
  "\n"
  "   ~ D0 <-> D1 (Rb1, Rd1d0)\n"
  "   ~ D1 <-> D2 (Rb2, Rd2d1)\n"
  "   ~ D2 <-> D3 (Rb1, Rd3d2)\n"
  "   ~ D0 <-> D1 (Rb1, Rd4d3)\n"
  "   ~ D0 <-> D1 (Rb1, Rd5d4)\n"
  "\n"
  "   ~ D0 <-> SD0 (Rsd0, Rrsd0)\n"
  "   ~ D1 <-> SD1 (Rsd1, Rrsd1)\n"
  "   ~ D2 <-> SD2 (Rsd2, Rrsd2)\n"
  "   ~ D3 <-> SD3 (Rsd3, Rrsd3)\n"
  "   ~ D4 <-> SD4 (Rsd4, Rrsd4)\n"
  "   ~ D5 <-> SD5 (Rsd5, Rrsd5)\n"
  "\n"
  "   ~ SD0 <-> SD1 (Rb1, Rsd1sd0)\n"
  "   ~ SD1 <-> SD2 (Rb2, Rsd2sd1)\n"
  "   ~ SD2 <-> SD3 (Rb3, Rsd3sd2)\n"
  "   ~ SD3 <-> SD4 (Rb4, Rsd4sd3)\n"
  "   ~ SD4 <-> SD5 (Rb5, Rsd5sd4)\n"
  "\n"
  "  CONSERVE C5 + C4 + C3 + C2 + C1 + C0 + O1 + O2 + O3 + O4 + O5 + D0 + D1 + D2 + D3 + D4 + D5 + SD0 + SD1 + SD2 + SD3 + SD4 +SD5= 1\n"
  " }\n"
  ;
#endif
