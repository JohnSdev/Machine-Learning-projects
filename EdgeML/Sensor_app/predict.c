#include <stdio.h>
#include <string.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
#include "model.h"

#include "predict.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

uint8_t predictTemp(int16_t series[]) {
int16_t two[101] = { 9969, 10049, 10049, 10009, 10049, 10069, 10069, 10069, 10069, 10049, 10049, 10069, 10069, 10049, 10049, 10069, 10069, 10049, 10049, 10069, 10069, 10049, 10049, 10069, 10069, 10049, 10049, 10069, 10069, 10049, 10049, 10069, 10069, 10049, 10049, 10069, 10069, 10049, 10049, 10069, 10069, 10049, 10009, 10069, 10069, 10049, 10049, 10069, 10069, 10049, 10049, 10069, 10069, 10049, 10049, 10069, 10069, 10049, 10049, 10069, 10069, 10049, 10049, 10069, 10069, 10069, 10049, 10069, 10069, 10069, 10049, 10069, 10069, 10069, 10049, 10069, 9769, 9649, 9629, 9649, 9729, 9649, 9609, 9649, 9729, 11811, 11911, 11911, 11911, 11911, 11911, 11911, 11911, 11911, 11210, 9929, 9769, 9749, 9649, 9669, 4096};
int16_t one[101] = { 11491, 11651, 11651, 11651, 11651, 11611, 11651, 11651, 11651, 11651, 11651, 11651, 11651, 11651, 11651, 11651, 11651, 11651, 11651, 11611, 11651, 11651, 11651, 11651, 11651, 11651, 11651, 11651, 11651, 11651, 11651, 11651, 11651, 11651, 11651, 11651, 11651, 11651, 11611, 11611, 11651, 11651, 11611, 11651, 11651, 11651, 11611, 11591, 11651, 11651, 11591, 11591, 11651, 11651, 11591, 11591, 11611, 11651, 11591, 11591, 11611, 11271, 11130, 11070, 11130, 11130, 11070, 11070, 11110, 11070, 11070, 11030, 11130, 11110, 11070, 11030, 12171, 12191, 12191, 12191, 12191, 12191, 11371, 11130, 11130, 11130, 11110, 11070, 11130, 11130, 11070, 11070, 11130, 11130, 11070, 11070, 11130, 11130, 11070, 11070, 4096};

	// ********
	// ML MODEL
	// ********
	int16_t serie[11] = {13440, 12687, 13440, 13440, 13936, 13936, 14187, 13936, 13440, 13936, 512};
	int16_t serie2[11] = {12436, 12436, 12436, 12436, 12436, 12436, 12436, 11934, 12185, 12185, 512};
	int16_t tmp0[28][1];
	int16_t tmp1;
	int16_t tmp2;
	int16_t tmp3;
	int16_t tmp4;
	int16_t tmp5;
	int16_t tmp6;
	int16_t tmp7[28][1];
	int16_t tmp8;
	int16_t tmp9;
	int16_t node0;
	int16_t tmp10[3][1];
	int16_t tmp11;
	int16_t tmp12;
	int16_t tmp13[28];
	int16_t tmp14;
	int16_t tmp15;
	int16_t tmp16[3][1];
	int16_t tmp17;
	int16_t tmp18;
	int16_t tmp19[28];
	int16_t tmp20;
	int16_t tmp21;
	int16_t tmp22[3][1];
	int16_t tmp23[1][1];
	int16_t tmp24;
	int16_t tmp25;
	int16_t tmp26[28];
	int16_t tmp27;
	int16_t tmp28;
	int16_t node1;
	int16_t tmp29[3][1];
	int16_t tmp30;
	int16_t tmp31;
	int16_t tmp32[28];
	int16_t tmp33;
	int16_t tmp34;
	int16_t tmp35[3][1];
	int16_t tmp36;
	int16_t tmp37;
	int16_t tmp38[28];
	int16_t tmp39;
	int16_t tmp40;
	int16_t tmp41[3][1];
	int16_t tmp42[3][1];
	int16_t tmp43;
	int16_t tmp44;
	int16_t tmp45[1][1];
	int16_t tmp46;
	int16_t tmp47;
	int16_t tmp48[28];
	int16_t tmp49;
	int16_t tmp50;
	int16_t node2;
	int16_t tmp51[3][1];
	int16_t tmp52;
	int16_t tmp53;
	int16_t tmp54[28];
	int16_t tmp55;
	int16_t tmp56;
	int16_t tmp57[3][1];
	int16_t tmp58;
	int16_t tmp59;
	int16_t tmp60[28];
	int16_t tmp61;
	int16_t tmp62;
	int16_t tmp63[3][1];
	int16_t tmp64[3][1];
	int16_t tmp65;
	int16_t tmp66;
	int16_t tmp67[1][1];
	int16_t tmp68;
	int16_t tmp69;
	int16_t tmp70[28];
	int16_t tmp71;
	int16_t tmp72;
	int16_t node3;
	int16_t tmp73[3][1];
	int16_t tmp74;
	int16_t tmp75;
	int16_t tmp76[28];
	int16_t tmp77;
	int16_t tmp78;
	int16_t tmp79[3][1];
	int16_t tmp80;
	int16_t tmp81;
	int16_t tmp82[28];
	int16_t tmp83;
	int16_t tmp84;
	int16_t tmp85[3][1];
	int16_t tmp86[3][1];
	int16_t tmp87;
	int16_t tmp88;
	int16_t tmp91;
	int16_t tmp89;
	int16_t tmp90;



	// ZZ |*| XX
	memset(tmp0, 0, sizeof(int16_t) * 28);
	tmp1 = 0;
	tmp2 = 0;
	for (int16_t i0 = 0; (i0 < 101); i0++) {

		tmp5 = series[i0];
		tmp5 = (tmp5 / 128);
		tmp3 = ((int16_t) pgm_read_word_near(&Zidx[tmp1]));
		while ((tmp3 != 0)) {
			tmp4 = ((int16_t) pgm_read_word_near(&Zval[tmp2]));
			tmp4 = (tmp4 / 128);
			tmp6 = (tmp4 * tmp5);
			tmp6 = (tmp6 / 4);
			tmp0[(tmp3 - 1)][0] = (tmp0[(tmp3 - 1)][0] + tmp6);
			tmp1 = (tmp1 + 1);
			tmp2 = (tmp2 + 1);
			tmp3 = ((int16_t) pgm_read_word_near(&Zidx[tmp1]));
		}
		tmp1 = (tmp1 + 1);
	}

	// tmp0 - Mean
	for (int16_t i1 = 0; (i1 < 28); i1++) {
		for (int16_t i2 = 0; (i2 < 1); i2++) {
			tmp8 = (tmp0[i1][i2] / 2);
			tmp9 = ((int16_t) pgm_read_word_near(&mean[i1][i2]));
			tmp7[i1][i2] = (tmp8 - tmp9);
			tmp7[i1][i2] = tmp7[i1][i2];
		}
	}
	node0 = 0;

	// WW * ZX
	for (int16_t i3 = 0; (i3 < 3); i3++) {
		for (int16_t i5 = 0; (i5 < 1); i5++) {
			for (int16_t i4 = 0; (i4 < 28); i4++) {
				tmp11 = (((int16_t) pgm_read_word_near(&W[node0][i3][i4])) / 64);
				tmp12 = (tmp7[i4][i5] / 64);
				tmp13[i4] = (tmp11 * tmp12);
			}
			tmp14 = 28;
			for (int16_t i6 = 0; (i6 < 0); i6++) {
				tmp15 = 0;
				for (int16_t i7 = 0; (i7 < 15); i7++) {
					tmp13[i7] = ((tmp15 < (tmp14 >> 1)) ? ((tmp13[(2 * i7)] + tmp13[((2 * i7) + 1)]) / 2) : (((tmp15 == (tmp14 >> 1)) && ((tmp14 & 1) == 1)) ? (tmp13[(2 * i7)] / 2) : 0));
					tmp15 = (tmp15 + 1);
				}
				tmp14 = ((tmp14 + 1) >> 1);
			}
			for (int16_t i6 = 0; (i6 < 5); i6++) {
				tmp15 = 0;
				for (int16_t i7 = 0; (i7 < 15); i7++) {
					tmp13[i7] = ((tmp15 < (tmp14 >> 1)) ? (tmp13[(2 * i7)] + tmp13[((2 * i7) + 1)]) : (((tmp15 == (tmp14 >> 1)) && ((tmp14 & 1) == 1)) ? tmp13[(2 * i7)] : 0));
					tmp15 = (tmp15 + 1);
				}
				tmp14 = ((tmp14 + 1) >> 1);
			}
			tmp10[i3][i5] = tmp13[0];
		}
	}

	// VV * ZX
	for (int16_t i8 = 0; (i8 < 3); i8++) {
		for (int16_t i10 = 0; (i10 < 1); i10++) {
			for (int16_t i9 = 0; (i9 < 28); i9++) {
				tmp17 = (((int16_t) pgm_read_word_near(&V[node0][i8][i9])) / 64);
				tmp18 = (tmp7[i9][i10] / 64);
				tmp19[i9] = (tmp17 * tmp18);
			}
			tmp20 = 28;
			for (int16_t i11 = 0; (i11 < 0); i11++) {
				tmp21 = 0;
				for (int16_t i12 = 0; (i12 < 15); i12++) {
					tmp19[i12] = ((tmp21 < (tmp20 >> 1)) ? ((tmp19[(2 * i12)] + tmp19[((2 * i12) + 1)]) / 2) : (((tmp21 == (tmp20 >> 1)) && ((tmp20 & 1) == 1)) ? (tmp19[(2 * i12)] / 2) : 0));
					tmp21 = (tmp21 + 1);
				}
				tmp20 = ((tmp20 + 1) >> 1);
			}
			for (int16_t i11 = 0; (i11 < 5); i11++) {
				tmp21 = 0;
				for (int16_t i12 = 0; (i12 < 15); i12++) {
					tmp19[i12] = ((tmp21 < (tmp20 >> 1)) ? (tmp19[(2 * i12)] + tmp19[((2 * i12) + 1)]) : (((tmp21 == (tmp20 >> 1)) && ((tmp20 & 1) == 1)) ? tmp19[(2 * i12)] : 0));
					tmp21 = (tmp21 + 1);
				}
				tmp20 = ((tmp20 + 1) >> 1);
			}
			tmp16[i8][i10] = tmp19[0];
		}
	}

	// tanh(V0)
	for (int16_t i13 = 0; (i13 < 3); i13++) {
		for (int16_t i14 = 0; (i14 < 1); i14++) {
			tmp16[i13][i14] = ((tmp16[i13][i14] >= 2048) ? 2048 : ((tmp16[i13][i14] <= -2048) ? -2048 : tmp16[i13][i14]));
		}
	}
	for (int16_t i15 = 0; (i15 < 3); i15++) {
		for (int16_t i16 = 0; (i16 < 1); i16++) {
			tmp22[i15][i16] = ((tmp10[i15][i16] / 64) * (tmp16[i15][i16] / 32));
		}
	}

	// TT * ZX
	for (int16_t i17 = 0; (i17 < 1); i17++) {
		for (int16_t i19 = 0; (i19 < 1); i19++) {
			for (int16_t i18 = 0; (i18 < 28); i18++) {
				tmp24 = (((int16_t) pgm_read_word_near(&T[node0][i17][i18])) / 64);
				tmp25 = (tmp7[i18][i19] / 64);
				tmp26[i18] = (tmp24 * tmp25);
			}
			tmp27 = 28;
			for (int16_t i20 = 0; (i20 < 0); i20++) {
				tmp28 = 0;
				for (int16_t i21 = 0; (i21 < 15); i21++) {
					tmp26[i21] = ((tmp28 < (tmp27 >> 1)) ? ((tmp26[(2 * i21)] + tmp26[((2 * i21) + 1)]) / 2) : (((tmp28 == (tmp27 >> 1)) && ((tmp27 & 1) == 1)) ? (tmp26[(2 * i21)] / 2) : 0));
					tmp28 = (tmp28 + 1);
				}
				tmp27 = ((tmp27 + 1) >> 1);
			}
			for (int16_t i20 = 0; (i20 < 5); i20++) {
				tmp28 = 0;
				for (int16_t i21 = 0; (i21 < 15); i21++) {
					tmp26[i21] = ((tmp28 < (tmp27 >> 1)) ? (tmp26[(2 * i21)] + tmp26[((2 * i21) + 1)]) : (((tmp28 == (tmp27 >> 1)) && ((tmp27 & 1) == 1)) ? tmp26[(2 * i21)] : 0));
					tmp28 = (tmp28 + 1);
				}
				tmp27 = ((tmp27 + 1) >> 1);
			}
			tmp23[i17][i19] = tmp26[0];
		}
	}
	node1 = ((tmp23[0][0] > 0) ? ((2 * node0) + 1) : ((2 * node0) + 2));

	// WW * ZX
	for (int16_t i22 = 0; (i22 < 3); i22++) {
		for (int16_t i24 = 0; (i24 < 1); i24++) {
			for (int16_t i23 = 0; (i23 < 28); i23++) {
				tmp30 = (((int16_t) pgm_read_word_near(&W[node1][i22][i23])) / 64);
				tmp31 = (tmp7[i23][i24] / 64);
				tmp32[i23] = (tmp30 * tmp31);
			}
			tmp33 = 28;
			for (int16_t i25 = 0; (i25 < 0); i25++) {
				tmp34 = 0;
				for (int16_t i26 = 0; (i26 < 15); i26++) {
					tmp32[i26] = ((tmp34 < (tmp33 >> 1)) ? ((tmp32[(2 * i26)] + tmp32[((2 * i26) + 1)]) / 2) : (((tmp34 == (tmp33 >> 1)) && ((tmp33 & 1) == 1)) ? (tmp32[(2 * i26)] / 2) : 0));
					tmp34 = (tmp34 + 1);
				}
				tmp33 = ((tmp33 + 1) >> 1);
			}
			for (int16_t i25 = 0; (i25 < 5); i25++) {
				tmp34 = 0;
				for (int16_t i26 = 0; (i26 < 15); i26++) {
					tmp32[i26] = ((tmp34 < (tmp33 >> 1)) ? (tmp32[(2 * i26)] + tmp32[((2 * i26) + 1)]) : (((tmp34 == (tmp33 >> 1)) && ((tmp33 & 1) == 1)) ? tmp32[(2 * i26)] : 0));
					tmp34 = (tmp34 + 1);
				}
				tmp33 = ((tmp33 + 1) >> 1);
			}
			tmp29[i22][i24] = tmp32[0];
		}
	}

	// VV * ZX
	for (int16_t i27 = 0; (i27 < 3); i27++) {
		for (int16_t i29 = 0; (i29 < 1); i29++) {
			for (int16_t i28 = 0; (i28 < 28); i28++) {
				tmp36 = (((int16_t) pgm_read_word_near(&V[node1][i27][i28])) / 64);
				tmp37 = (tmp7[i28][i29] / 64);
				tmp38[i28] = (tmp36 * tmp37);
			}
			tmp39 = 28;
			for (int16_t i30 = 0; (i30 < 0); i30++) {
				tmp40 = 0;
				for (int16_t i31 = 0; (i31 < 15); i31++) {
					tmp38[i31] = ((tmp40 < (tmp39 >> 1)) ? ((tmp38[(2 * i31)] + tmp38[((2 * i31) + 1)]) / 2) : (((tmp40 == (tmp39 >> 1)) && ((tmp39 & 1) == 1)) ? (tmp38[(2 * i31)] / 2) : 0));
					tmp40 = (tmp40 + 1);
				}
				tmp39 = ((tmp39 + 1) >> 1);
			}
			for (int16_t i30 = 0; (i30 < 5); i30++) {
				tmp40 = 0;
				for (int16_t i31 = 0; (i31 < 15); i31++) {
					tmp38[i31] = ((tmp40 < (tmp39 >> 1)) ? (tmp38[(2 * i31)] + tmp38[((2 * i31) + 1)]) : (((tmp40 == (tmp39 >> 1)) && ((tmp39 & 1) == 1)) ? tmp38[(2 * i31)] : 0));
					tmp40 = (tmp40 + 1);
				}
				tmp39 = ((tmp39 + 1) >> 1);
			}
			tmp35[i27][i29] = tmp38[0];
		}
	}

	// tanh(V1)
	for (int16_t i32 = 0; (i32 < 3); i32++) {
		for (int16_t i33 = 0; (i33 < 1); i33++) {
			tmp35[i32][i33] = ((tmp35[i32][i33] >= 2048) ? 2048 : ((tmp35[i32][i33] <= -2048) ? -2048 : tmp35[i32][i33]));
		}
	}
	for (int16_t i34 = 0; (i34 < 3); i34++) {
		for (int16_t i35 = 0; (i35 < 1); i35++) {
			tmp41[i34][i35] = ((tmp29[i34][i35] / 64) * (tmp35[i34][i35] / 32));
		}
	}

	// score0 + tmp41
	for (int16_t i36 = 0; (i36 < 3); i36++) {
		for (int16_t i37 = 0; (i37 < 1); i37++) {
			tmp43 = tmp22[i36][i37];
			tmp44 = tmp41[i36][i37];
			tmp42[i36][i37] = (tmp43 + tmp44);
			tmp42[i36][i37] = tmp42[i36][i37];
		}
	}

	// TT * ZX
	for (int16_t i38 = 0; (i38 < 1); i38++) {
		for (int16_t i40 = 0; (i40 < 1); i40++) {
			for (int16_t i39 = 0; (i39 < 28); i39++) {
				tmp46 = (((int16_t) pgm_read_word_near(&T[node1][i38][i39])) / 64);
				tmp47 = (tmp7[i39][i40] / 64);
				tmp48[i39] = (tmp46 * tmp47);
			}
			tmp49 = 28;
			for (int16_t i41 = 0; (i41 < 0); i41++) {
				tmp50 = 0;
				for (int16_t i42 = 0; (i42 < 15); i42++) {
					tmp48[i42] = ((tmp50 < (tmp49 >> 1)) ? ((tmp48[(2 * i42)] + tmp48[((2 * i42) + 1)]) / 2) : (((tmp50 == (tmp49 >> 1)) && ((tmp49 & 1) == 1)) ? (tmp48[(2 * i42)] / 2) : 0));
					tmp50 = (tmp50 + 1);
				}
				tmp49 = ((tmp49 + 1) >> 1);
			}
			for (int16_t i41 = 0; (i41 < 5); i41++) {
				tmp50 = 0;
				for (int16_t i42 = 0; (i42 < 15); i42++) {
					tmp48[i42] = ((tmp50 < (tmp49 >> 1)) ? (tmp48[(2 * i42)] + tmp48[((2 * i42) + 1)]) : (((tmp50 == (tmp49 >> 1)) && ((tmp49 & 1) == 1)) ? tmp48[(2 * i42)] : 0));
					tmp50 = (tmp50 + 1);
				}
				tmp49 = ((tmp49 + 1) >> 1);
			}
			tmp45[i38][i40] = tmp48[0];
		}
	}
	node2 = ((tmp45[0][0] > 0) ? ((2 * node1) + 1) : ((2 * node1) + 2));

	// WW * ZX
	for (int16_t i43 = 0; (i43 < 3); i43++) {
		for (int16_t i45 = 0; (i45 < 1); i45++) {
			for (int16_t i44 = 0; (i44 < 28); i44++) {
				tmp52 = (((int16_t) pgm_read_word_near(&W[node2][i43][i44])) / 64);
				tmp53 = (tmp7[i44][i45] / 64);
				tmp54[i44] = (tmp52 * tmp53);
			}
			tmp55 = 28;
			for (int16_t i46 = 0; (i46 < 0); i46++) {
				tmp56 = 0;
				for (int16_t i47 = 0; (i47 < 15); i47++) {
					tmp54[i47] = ((tmp56 < (tmp55 >> 1)) ? ((tmp54[(2 * i47)] + tmp54[((2 * i47) + 1)]) / 2) : (((tmp56 == (tmp55 >> 1)) && ((tmp55 & 1) == 1)) ? (tmp54[(2 * i47)] / 2) : 0));
					tmp56 = (tmp56 + 1);
				}
				tmp55 = ((tmp55 + 1) >> 1);
			}
			for (int16_t i46 = 0; (i46 < 5); i46++) {
				tmp56 = 0;
				for (int16_t i47 = 0; (i47 < 15); i47++) {
					tmp54[i47] = ((tmp56 < (tmp55 >> 1)) ? (tmp54[(2 * i47)] + tmp54[((2 * i47) + 1)]) : (((tmp56 == (tmp55 >> 1)) && ((tmp55 & 1) == 1)) ? tmp54[(2 * i47)] : 0));
					tmp56 = (tmp56 + 1);
				}
				tmp55 = ((tmp55 + 1) >> 1);
			}
			tmp51[i43][i45] = tmp54[0];
		}
	}

	// VV * ZX
	for (int16_t i48 = 0; (i48 < 3); i48++) {
		for (int16_t i50 = 0; (i50 < 1); i50++) {
			for (int16_t i49 = 0; (i49 < 28); i49++) {
				tmp58 = (((int16_t) pgm_read_word_near(&V[node2][i48][i49])) / 64);
				tmp59 = (tmp7[i49][i50] / 64);
				tmp60[i49] = (tmp58 * tmp59);
			}
			tmp61 = 28;
			for (int16_t i51 = 0; (i51 < 0); i51++) {
				tmp62 = 0;
				for (int16_t i52 = 0; (i52 < 15); i52++) {
					tmp60[i52] = ((tmp62 < (tmp61 >> 1)) ? ((tmp60[(2 * i52)] + tmp60[((2 * i52) + 1)]) / 2) : (((tmp62 == (tmp61 >> 1)) && ((tmp61 & 1) == 1)) ? (tmp60[(2 * i52)] / 2) : 0));
					tmp62 = (tmp62 + 1);
				}
				tmp61 = ((tmp61 + 1) >> 1);
			}
			for (int16_t i51 = 0; (i51 < 5); i51++) {
				tmp62 = 0;
				for (int16_t i52 = 0; (i52 < 15); i52++) {
					tmp60[i52] = ((tmp62 < (tmp61 >> 1)) ? (tmp60[(2 * i52)] + tmp60[((2 * i52) + 1)]) : (((tmp62 == (tmp61 >> 1)) && ((tmp61 & 1) == 1)) ? tmp60[(2 * i52)] : 0));
					tmp62 = (tmp62 + 1);
				}
				tmp61 = ((tmp61 + 1) >> 1);
			}
			tmp57[i48][i50] = tmp60[0];
		}
	}

	// tanh(V2)
	for (int16_t i53 = 0; (i53 < 3); i53++) {
		for (int16_t i54 = 0; (i54 < 1); i54++) {
			tmp57[i53][i54] = ((tmp57[i53][i54] >= 2048) ? 2048 : ((tmp57[i53][i54] <= -2048) ? -2048 : tmp57[i53][i54]));
		}
	}
	for (int16_t i55 = 0; (i55 < 3); i55++) {
		for (int16_t i56 = 0; (i56 < 1); i56++) {
			tmp63[i55][i56] = ((tmp51[i55][i56] / 64) * (tmp57[i55][i56] / 32));
		}
	}

	// score1 + tmp63
	for (int16_t i57 = 0; (i57 < 3); i57++) {
		for (int16_t i58 = 0; (i58 < 1); i58++) {
			tmp65 = tmp42[i57][i58];
			tmp66 = tmp63[i57][i58];
			tmp64[i57][i58] = (tmp65 + tmp66);
			tmp64[i57][i58] = tmp64[i57][i58];
		}
	}

	// TT * ZX
	for (int16_t i59 = 0; (i59 < 1); i59++) {
		for (int16_t i61 = 0; (i61 < 1); i61++) {
			for (int16_t i60 = 0; (i60 < 28); i60++) {
				tmp68 = (((int16_t) pgm_read_word_near(&T[node2][i59][i60])) / 64);
				tmp69 = (tmp7[i60][i61] / 64);
				tmp70[i60] = (tmp68 * tmp69);
			}
			tmp71 = 28;
			for (int16_t i62 = 0; (i62 < 0); i62++) {
				tmp72 = 0;
				for (int16_t i63 = 0; (i63 < 15); i63++) {
					tmp70[i63] = ((tmp72 < (tmp71 >> 1)) ? ((tmp70[(2 * i63)] + tmp70[((2 * i63) + 1)]) / 2) : (((tmp72 == (tmp71 >> 1)) && ((tmp71 & 1) == 1)) ? (tmp70[(2 * i63)] / 2) : 0));
					tmp72 = (tmp72 + 1);
				}
				tmp71 = ((tmp71 + 1) >> 1);
			}
			for (int16_t i62 = 0; (i62 < 5); i62++) {
				tmp72 = 0;
				for (int16_t i63 = 0; (i63 < 15); i63++) {
					tmp70[i63] = ((tmp72 < (tmp71 >> 1)) ? (tmp70[(2 * i63)] + tmp70[((2 * i63) + 1)]) : (((tmp72 == (tmp71 >> 1)) && ((tmp71 & 1) == 1)) ? tmp70[(2 * i63)] : 0));
					tmp72 = (tmp72 + 1);
				}
				tmp71 = ((tmp71 + 1) >> 1);
			}
			tmp67[i59][i61] = tmp70[0];
		}
	}
	node3 = ((tmp67[0][0] > 0) ? ((2 * node2) + 1) : ((2 * node2) + 2));

	// WW * ZX
	for (int16_t i64 = 0; (i64 < 3); i64++) {
		for (int16_t i66 = 0; (i66 < 1); i66++) {
			for (int16_t i65 = 0; (i65 < 28); i65++) {
				tmp74 = (((int16_t) pgm_read_word_near(&W[node3][i64][i65])) / 64);
				tmp75 = (tmp7[i65][i66] / 64);
				tmp76[i65] = (tmp74 * tmp75);
			}
			tmp77 = 28;
			for (int16_t i67 = 0; (i67 < 0); i67++) {
				tmp78 = 0;
				for (int16_t i68 = 0; (i68 < 15); i68++) {
					tmp76[i68] = ((tmp78 < (tmp77 >> 1)) ? ((tmp76[(2 * i68)] + tmp76[((2 * i68) + 1)]) / 2) : (((tmp78 == (tmp77 >> 1)) && ((tmp77 & 1) == 1)) ? (tmp76[(2 * i68)] / 2) : 0));
					tmp78 = (tmp78 + 1);
				}
				tmp77 = ((tmp77 + 1) >> 1);
			}
			for (int16_t i67 = 0; (i67 < 5); i67++) {
				tmp78 = 0;
				for (int16_t i68 = 0; (i68 < 15); i68++) {
					tmp76[i68] = ((tmp78 < (tmp77 >> 1)) ? (tmp76[(2 * i68)] + tmp76[((2 * i68) + 1)]) : (((tmp78 == (tmp77 >> 1)) && ((tmp77 & 1) == 1)) ? tmp76[(2 * i68)] : 0));
					tmp78 = (tmp78 + 1);
				}
				tmp77 = ((tmp77 + 1) >> 1);
			}
			tmp73[i64][i66] = tmp76[0];
		}
	}

	// VV * ZX
	for (int16_t i69 = 0; (i69 < 3); i69++) {
		for (int16_t i71 = 0; (i71 < 1); i71++) {
			for (int16_t i70 = 0; (i70 < 28); i70++) {
				tmp80 = (((int16_t) pgm_read_word_near(&V[node3][i69][i70])) / 64);
				tmp81 = (tmp7[i70][i71] / 64);
				tmp82[i70] = (tmp80 * tmp81);
			}
			tmp83 = 28;
			for (int16_t i72 = 0; (i72 < 0); i72++) {
				tmp84 = 0;
				for (int16_t i73 = 0; (i73 < 15); i73++) {
					tmp82[i73] = ((tmp84 < (tmp83 >> 1)) ? ((tmp82[(2 * i73)] + tmp82[((2 * i73) + 1)]) / 2) : (((tmp84 == (tmp83 >> 1)) && ((tmp83 & 1) == 1)) ? (tmp82[(2 * i73)] / 2) : 0));
					tmp84 = (tmp84 + 1);
				}
				tmp83 = ((tmp83 + 1) >> 1);
			}
			for (int16_t i72 = 0; (i72 < 5); i72++) {
				tmp84 = 0;
				for (int16_t i73 = 0; (i73 < 15); i73++) {
					tmp82[i73] = ((tmp84 < (tmp83 >> 1)) ? (tmp82[(2 * i73)] + tmp82[((2 * i73) + 1)]) : (((tmp84 == (tmp83 >> 1)) && ((tmp83 & 1) == 1)) ? tmp82[(2 * i73)] : 0));
					tmp84 = (tmp84 + 1);
				}
				tmp83 = ((tmp83 + 1) >> 1);
			}
			tmp79[i69][i71] = tmp82[0];
		}
	}

	// tanh(V3)
	for (int16_t i74 = 0; (i74 < 3); i74++) {
		for (int16_t i75 = 0; (i75 < 1); i75++) {
			tmp79[i74][i75] = ((tmp79[i74][i75] >= 2048) ? 2048 : ((tmp79[i74][i75] <= -2048) ? -2048 : tmp79[i74][i75]));
		}
	}
	for (int16_t i76 = 0; (i76 < 3); i76++) {
		for (int16_t i77 = 0; (i77 < 1); i77++) {
			tmp85[i76][i77] = ((tmp73[i76][i77] / 64) * (tmp79[i76][i77] / 32));
		}
	}

	// score2 + tmp85
	for (int16_t i78 = 0; (i78 < 3); i78++) {
		for (int16_t i79 = 0; (i79 < 1); i79++) {
			tmp87 = tmp64[i78][i79];
			tmp88 = tmp85[i78][i79];
			tmp86[i78][i79] = (tmp87 + tmp88);
			tmp86[i78][i79] = tmp86[i78][i79];
		}
	}
	tmp91 = 0;
	tmp89 = 0;
	tmp90 = tmp86[0][0];
	for (int16_t i80 = 0; (i80 < 3); i80++) {
		for (int16_t i81 = 0; (i81 < 1); i81++) {
			if ((tmp90 < tmp86[i80][i81])) {
				tmp89 = tmp91;
				tmp90 = tmp86[i80][i81];
			}
			tmp91 = (tmp91 + 1);
		}
	}
	
	return tmp89;
}
