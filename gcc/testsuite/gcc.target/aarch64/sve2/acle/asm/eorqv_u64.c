/* { dg-do assemble { target aarch64_asm_sve2p1_ok } } */
/* { dg-do compile { target { ! aarch64_asm_sve2p1_ok } } } */
/* { dg-skip-if "" { *-*-* } { "-DSTREAMING_COMPATIBLE" } { "" } } */
/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sve_acle.h"

#pragma GCC target "+sve2p1"

/*
** eorqv_d0_u64_tied:
**	eorqv	v0\.2d, p0, z0\.d
**	ret
*/
TEST_REDUCTION_D (eorqv_d0_u64_tied, uint64x2_t, svuint64_t,
		  d0 = sveorqv_u64 (p0, z0),
		  d0 = sveorqv (p0, z0))

/*
** eorqv_d0_u64_untied:
**	eorqv	v0\.2d, p0, z1\.d
**	ret
*/
TEST_REDUCTION_D (eorqv_d0_u64_untied, uint64x2_t, svuint64_t,
		  d0 = sveorqv_u64 (p0, z1),
		  d0 = sveorqv (p0, z1))
