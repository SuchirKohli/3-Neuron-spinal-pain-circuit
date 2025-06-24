#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

extern void _AMPA_reg();
extern void _Ca12L_reg();
extern void _GABAA_reg();
extern void _GABAB_reg();
extern void _HCN1_reg();
extern void _HCN2_reg();
extern void _KV11HH_reg();
extern void _KV12HH_reg();
extern void _KV13HH_reg();
extern void _NMDA_reg();
extern void _NaKpump_reg();
extern void _NaV11_reg();
extern void _NaV12_reg();
extern void _NaV16_reg();
extern void _a3b4_reg();
extern void _a4b2_reg();
extern void _a7_reg();
extern void _achrelease_reg();
extern void _cadyn_reg();
extern void _capump_reg();
extern void _gabafrelease_reg();
extern void _glurelease_reg();
extern void _leak_reg();
extern void _release_reg();

void modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," AMPA.mod");
fprintf(stderr," Ca12L.mod");
fprintf(stderr," GABAA.mod");
fprintf(stderr," GABAB.mod");
fprintf(stderr," HCN1.mod");
fprintf(stderr," HCN2.mod");
fprintf(stderr," KV11HH.mod");
fprintf(stderr," KV12HH.mod");
fprintf(stderr," KV13HH.mod");
fprintf(stderr," NMDA.mod");
fprintf(stderr," NaKpump.mod");
fprintf(stderr," NaV11.mod");
fprintf(stderr," NaV12.mod");
fprintf(stderr," NaV16.mod");
fprintf(stderr," a3b4.mod");
fprintf(stderr," a4b2.mod");
fprintf(stderr," a7.mod");
fprintf(stderr," achrelease.mod");
fprintf(stderr," cadyn.mod");
fprintf(stderr," capump.mod");
fprintf(stderr," gabafrelease.mod");
fprintf(stderr," glurelease.mod");
fprintf(stderr," leak.mod");
fprintf(stderr," release.mod");
fprintf(stderr, "\n");
    }
_AMPA_reg();
_Ca12L_reg();
_GABAA_reg();
_GABAB_reg();
_HCN1_reg();
_HCN2_reg();
_KV11HH_reg();
_KV12HH_reg();
_KV13HH_reg();
_NMDA_reg();
_NaKpump_reg();
_NaV11_reg();
_NaV12_reg();
_NaV16_reg();
_a3b4_reg();
_a4b2_reg();
_a7_reg();
_achrelease_reg();
_cadyn_reg();
_capump_reg();
_gabafrelease_reg();
_glurelease_reg();
_leak_reg();
_release_reg();
}
