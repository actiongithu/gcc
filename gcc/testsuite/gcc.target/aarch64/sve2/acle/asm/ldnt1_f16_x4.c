/* { dg-do assemble { target aarch64_asm_sve2p1_ok } } */
/* { dg-do compile { target { ! aarch64_asm_sve2p1_ok } } } */
/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" { target { ! ilp32 } } } } */

#include "test_sve_acle.h"

#pragma GCC target "+sve2p1"
#ifdef STREAMING_COMPATIBLE
#pragma GCC target "+sme2"
#endif

/*
** ldnt1_f16_base:
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_f16_base, svfloat16x4_t, float16_t,
		 z0 = svldnt1_f16_x4 (pn8, x0),
		 z0 = svldnt1_x4 (pn8, x0))

/*
** ldnt1_f16_index:
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0, x1, lsl #?1\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_f16_index, svfloat16x4_t, float16_t,
		 z0 = svldnt1_f16_x4 (pn8, x0 + x1),
		 z0 = svldnt1_x4 (pn8, x0 + x1))

/* Moving the constant into a register would also be OK.  */
/*
** ldnt1_f16_1:
**	incb	x0
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_f16_1, svfloat16x4_t, float16_t,
		 z0 = svldnt1_f16_x4 (pn8, x0 + svcnth ()),
		 z0 = svldnt1_x4 (pn8, x0 + svcnth ()))

/* Moving the constant into a register would also be OK.  */
/*
** ldnt1_f16_2:
**	incb	x0, all, mul #2
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_f16_2, svfloat16x4_t, float16_t,
		 z0 = svldnt1_f16_x4 (pn8, x0 + svcnth () * 2),
		 z0 = svldnt1_x4 (pn8, x0 + svcnth () * 2))

/* Moving the constant into a register would also be OK.  */
/*
** ldnt1_f16_3:
**	incb	x0, all, mul #3
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_f16_3, svfloat16x4_t, float16_t,
		 z0 = svldnt1_f16_x4 (pn8, x0 + svcnth () * 3),
		 z0 = svldnt1_x4 (pn8, x0 + svcnth () * 3))

/*
** ldnt1_f16_4:
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0, #4, mul vl\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_f16_4, svfloat16x4_t, float16_t,
		 z0 = svldnt1_f16_x4 (pn8, x0 + svcnth () * 4),
		 z0 = svldnt1_x4 (pn8, x0 + svcnth () * 4))

/*
** ldnt1_f16_28:
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0, #28, mul vl\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_f16_28, svfloat16x4_t, float16_t,
		 z0 = svldnt1_f16_x4 (pn8, x0 + svcnth () * 28),
		 z0 = svldnt1_x4 (pn8, x0 + svcnth () * 28))

/*
** ldnt1_f16_32:
**	[^{]*
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x[0-9]+\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_f16_32, svfloat16x4_t, float16_t,
		 z0 = svldnt1_f16_x4 (pn8, x0 + svcnth () * 32),
		 z0 = svldnt1_x4 (pn8, x0 + svcnth () * 32))

/* Moving the constant into a register would also be OK.  */
/*
** ldnt1_f16_m1:
**	decb	x0
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_f16_m1, svfloat16x4_t, float16_t,
		 z0 = svldnt1_f16_x4 (pn8, x0 - svcnth ()),
		 z0 = svldnt1_x4 (pn8, x0 - svcnth ()))

/* Moving the constant into a register would also be OK.  */
/*
** ldnt1_f16_m2:
**	decb	x0, all, mul #2
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_f16_m2, svfloat16x4_t, float16_t,
		 z0 = svldnt1_f16_x4 (pn8, x0 - svcnth () * 2),
		 z0 = svldnt1_x4 (pn8, x0 - svcnth () * 2))

/* Moving the constant into a register would also be OK.  */
/*
** ldnt1_f16_m3:
**	decb	x0, all, mul #3
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_f16_m3, svfloat16x4_t, float16_t,
		 z0 = svldnt1_f16_x4 (pn8, x0 - svcnth () * 3),
		 z0 = svldnt1_x4 (pn8, x0 - svcnth () * 3))

/*
** ldnt1_f16_m4:
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0, #-4, mul vl\]
**	ret
*/
  TEST_LOAD_COUNT (ldnt1_f16_m4, svfloat16x4_t, float16_t,
		   z0 = svldnt1_f16_x4 (pn8, x0 - svcnth () * 4),
		   z0 = svldnt1_x4 (pn8, x0 - svcnth () * 4))

/*
** ldnt1_f16_m32:
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0, #-32, mul vl\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_f16_m32, svfloat16x4_t, float16_t,
		 z0 = svldnt1_f16_x4 (pn8, x0 - svcnth () * 32),
		 z0 = svldnt1_x4 (pn8, x0 - svcnth () * 32))

/*
** ldnt1_f16_m36:
**	[^{]*
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x[0-9]+\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_f16_m36, svfloat16x4_t, float16_t,
		 z0 = svldnt1_f16_x4 (pn8, x0 - svcnth () * 36),
		 z0 = svldnt1_x4 (pn8, x0 - svcnth () * 36))

/*
** ldnt1_f16_z17:
**	ldnt1h	{z[^\n]+}, pn8/z, \[x0\]
**	mov	[^\n]+
**	mov	[^\n]+
**	mov	[^\n]+
**	mov	[^\n]+
**	ret
*/
TEST_LOAD_COUNT (ldnt1_f16_z17, svfloat16x4_t, float16_t,
		 z17 = svldnt1_f16_x4 (pn8, x0),
		 z17 = svldnt1_x4 (pn8, x0))

/*
** ldnt1_f16_z22:
**	ldnt1h	{z[^\n]+}, pn8/z, \[x0\]
**	mov	[^\n]+
**	mov	[^\n]+
**	mov	[^\n]+
**	mov	[^\n]+
**	ret
*/
TEST_LOAD_COUNT (ldnt1_f16_z22, svfloat16x4_t, float16_t,
		 z22 = svldnt1_f16_x4 (pn8, x0),
		 z22 = svldnt1_x4 (pn8, x0))

/*
** ldnt1_f16_z28:
**	ldnt1h	{z28\.h(?: - |, )z31\.h}, pn8/z, \[x0\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_f16_z28, svfloat16x4_t, float16_t,
		 z28 = svldnt1_f16_x4 (pn8, x0),
		 z28 = svldnt1_x4 (pn8, x0))

/*
** ldnt1_f16_pn0:
**	mov	p([89]|1[0-5])\.b, p0\.b
**	ldnt1h	{z0\.h(?: - |, )z3\.h}, pn\1/z, \[x0\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_f16_pn0, svfloat16x4_t, float16_t,
		 z0 = svldnt1_f16_x4 (pn0, x0),
		 z0 = svldnt1_x4 (pn0, x0))

/*
** ldnt1_f16_pn7:
**	mov	p([89]|1[0-5])\.b, p7\.b
**	ldnt1h	{z0\.h(?: - |, )z3\.h}, pn\1/z, \[x0\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_f16_pn7, svfloat16x4_t, float16_t,
		 z0 = svldnt1_f16_x4 (pn7, x0),
		 z0 = svldnt1_x4 (pn7, x0))

/*
** ldnt1_f16_pn15:
**	ldnt1h	{z0\.h(?: - |, )z3\.h}, pn15/z, \[x0\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_f16_pn15, svfloat16x4_t, float16_t,
		 z0 = svldnt1_f16_x4 (pn15, x0),
		 z0 = svldnt1_x4 (pn15, x0))

/*
** ldnt1_vnum_f16_0:
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_vnum_f16_0, svfloat16x4_t, float16_t,
		 z0 = svldnt1_vnum_f16_x4 (pn8, x0, 0),
		 z0 = svldnt1_vnum_x4 (pn8, x0, 0))

/* Moving the constant into a register would also be OK.  */
/*
** ldnt1_vnum_f16_1:
**	incb	x0
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_vnum_f16_1, svfloat16x4_t, float16_t,
		 z0 = svldnt1_vnum_f16_x4 (pn8, x0, 1),
		 z0 = svldnt1_vnum_x4 (pn8, x0, 1))

/* Moving the constant into a register would also be OK.  */
/*
** ldnt1_vnum_f16_2:
**	incb	x0, all, mul #2
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_vnum_f16_2, svfloat16x4_t, float16_t,
		 z0 = svldnt1_vnum_f16_x4 (pn8, x0, 2),
		 z0 = svldnt1_vnum_x4 (pn8, x0, 2))

/* Moving the constant into a register would also be OK.  */
/*
** ldnt1_vnum_f16_3:
**	incb	x0, all, mul #3
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_vnum_f16_3, svfloat16x4_t, float16_t,
		 z0 = svldnt1_vnum_f16_x4 (pn8, x0, 3),
		 z0 = svldnt1_vnum_x4 (pn8, x0, 3))

/*
** ldnt1_vnum_f16_4:
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0, #4, mul vl\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_vnum_f16_4, svfloat16x4_t, float16_t,
		 z0 = svldnt1_vnum_f16_x4 (pn8, x0, 4),
		 z0 = svldnt1_vnum_x4 (pn8, x0, 4))

/*
** ldnt1_vnum_f16_28:
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0, #28, mul vl\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_vnum_f16_28, svfloat16x4_t, float16_t,
		 z0 = svldnt1_vnum_f16_x4 (pn8, x0, 28),
		 z0 = svldnt1_vnum_x4 (pn8, x0, 28))

/*
** ldnt1_vnum_f16_32:
**	[^{]*
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x[0-9]+\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_vnum_f16_32, svfloat16x4_t, float16_t,
		 z0 = svldnt1_vnum_f16_x4 (pn8, x0, 32),
		 z0 = svldnt1_vnum_x4 (pn8, x0, 32))

/* Moving the constant into a register would also be OK.  */
/*
** ldnt1_vnum_f16_m1:
**	decb	x0
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_vnum_f16_m1, svfloat16x4_t, float16_t,
		 z0 = svldnt1_vnum_f16_x4 (pn8, x0, -1),
		 z0 = svldnt1_vnum_x4 (pn8, x0, -1))

/* Moving the constant into a register would also be OK.  */
/*
** ldnt1_vnum_f16_m2:
**	decb	x0, all, mul #2
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_vnum_f16_m2, svfloat16x4_t, float16_t,
		 z0 = svldnt1_vnum_f16_x4 (pn8, x0, -2),
		 z0 = svldnt1_vnum_x4 (pn8, x0, -2))

/* Moving the constant into a register would also be OK.  */
/*
** ldnt1_vnum_f16_m3:
**	decb	x0, all, mul #3
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_vnum_f16_m3, svfloat16x4_t, float16_t,
		 z0 = svldnt1_vnum_f16_x4 (pn8, x0, -3),
		 z0 = svldnt1_vnum_x4 (pn8, x0, -3))

/*
** ldnt1_vnum_f16_m4:
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0, #-4, mul vl\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_vnum_f16_m4, svfloat16x4_t, float16_t,
		 z0 = svldnt1_vnum_f16_x4 (pn8, x0, -4),
		 z0 = svldnt1_vnum_x4 (pn8, x0, -4))

/*
** ldnt1_vnum_f16_m32:
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0, #-32, mul vl\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_vnum_f16_m32, svfloat16x4_t, float16_t,
		 z0 = svldnt1_vnum_f16_x4 (pn8, x0, -32),
		 z0 = svldnt1_vnum_x4 (pn8, x0, -32))

/*
** ldnt1_vnum_f16_m36:
**	[^{]*
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x[0-9]+\]
**	ret
*/
TEST_LOAD_COUNT (ldnt1_vnum_f16_m36, svfloat16x4_t, float16_t,
		 z0 = svldnt1_vnum_f16_x4 (pn8, x0, -36),
		 z0 = svldnt1_vnum_x4 (pn8, x0, -36))

/*
** ldnt1_vnum_f16_x1:
**	cntb	(x[0-9]+)
** (
**	madd	(x[0-9]+), (?:x1, \1|\1, x1), x0
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[\2\]
** |
**	mul	(x[0-9]+), (?:x1, \1|\1, x1)
**	ldnt1h	{z0\.h - z3\.h}, pn8/z, \[x0, \3\]
** )
**	ret
*/
TEST_LOAD_COUNT (ldnt1_vnum_f16_x1, svfloat16x4_t, float16_t,
		 z0 = svldnt1_vnum_f16_x4 (pn8, x0, x1),
		 z0 = svldnt1_vnum_x4 (pn8, x0, x1))
