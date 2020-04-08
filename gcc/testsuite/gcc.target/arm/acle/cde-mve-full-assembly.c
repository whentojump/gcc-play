/* { dg-do compile } */
/* { dg-skip-if "Require optimisation to compile DCE tests" { *-*-* } { "-O0" "-mfloat-abi=softfp" } { "" } } */
/* { dg-require-effective-target arm_v8_1m_main_cde_mve_fp_ok } */
/* { dg-add-options arm_v8_1m_main_cde_mve_fp } */
/* We use -ffast-math so that the addition of 0.0 to a value is assumed to not
   change the value.  This means the tests for float types can use the same
   trick of adding to a value initialised to zero to check whether the RTL
   patterns correctly mark that the incoming value is not used.  */
/* { dg-additional-options "-ffast-math" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "cde-mve-tests.c"

/* NOTE:
     We avoid matching the functions returning a __builtin_neon_ti value since
     there are variations between processors that make matching the whole
     function difficult.
     Since moving a TImode value into an MVE 'Q' register takes a few
     temporaries, this leaves many instructions which can end up being
     scheduled in different ways.  Matching the ways this ends up getting
     scheduled and restructured is awkward, and the extra tests for this one
     data type don't seem to be worth the confusing testcases.  */

/*
** test_cde_vcx1q_u8float16x8_tintint:
** 	vcx1	p0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx1q_u8float32x4_tintint:
** 	vcx1	p0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx1q_u8uint8x16_tintint:
** 	vcx1	p0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx1q_u8uint16x8_tintint:
** 	vcx1	p0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx1q_u8uint32x4_tintint:
** 	vcx1	p0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx1q_u8uint64x2_tintint:
** 	vcx1	p0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx1q_u8int8x16_tintint:
** 	vcx1	p0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx1q_u8int16x8_tintint:
** 	vcx1	p0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx1q_u8int32x4_tintint:
** 	vcx1	p0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx1q_u8int64x2_tintint:
** 	vcx1	p0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx1qafloat16x8_tintint:
** 	vldr\.64	d0, \.L([0-9]*)
** 	vldr\.64	d1, \.L\1\+8
** 	vcx1a	p0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx1qafloat32x4_tintint:
** 	vldr\.64	d0, \.L([0-9]*)
** 	vldr\.64	d1, \.L\1\+8
** 	vcx1a	p0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx1qauint8x16_tintint:
** 	vldr\.64	d0, \.L([0-9]*)
** 	vldr\.64	d1, \.L\1\+8
** 	vcx1a	p0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx1qauint16x8_tintint:
** 	vldr\.64	d0, \.L([0-9]*)
** 	vldr\.64	d1, \.L\1\+8
** 	vcx1a	p0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx1qauint32x4_tintint:
** 	vldr\.64	d0, \.L([0-9]*)
** 	vldr\.64	d1, \.L\1\+8
** 	vcx1a	p0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx1qauint64x2_tintint:
** 	vldr\.64	d0, \.L([0-9]*)
** 	vldr\.64	d1, \.L\1\+8
** 	vcx1a	p0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx1qaint8x16_tintint:
** 	vldr\.64	d0, \.L([0-9]*)
** 	vldr\.64	d1, \.L\1\+8
** 	vcx1a	p0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx1qaint16x8_tintint:
** 	vldr\.64	d0, \.L([0-9]*)
** 	vldr\.64	d1, \.L\1\+8
** 	vcx1a	p0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx1qaint32x4_tintint:
** 	vldr\.64	d0, \.L([0-9]*)
** 	vldr\.64	d1, \.L\1\+8
** 	vcx1a	p0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx1qaint64x2_tintint:
** 	vldr\.64	d0, \.L([0-9]*)
** 	vldr\.64	d1, \.L\1\+8
** 	vcx1a	p0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx2q_u8float16x8_tuint16x8_tint:
** 	vcx2	p0, q0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx2q_u8float16x8_tfloat32x4_tint:
** 	vcx2	p0, q0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx2q_u8float32x4_tuint8x16_tint:
** 	vcx2	p0, q0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx2q_u8int64x2_tuint8x16_tint:
** 	vcx2	p0, q0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx2q_u8int8x16_tuint8x16_tint:
** 	vcx2	p0, q0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx2q_u8uint16x8_tuint8x16_tint:
** 	vcx2	p0, q0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx2q_u8uint8x16_tint64x2_tint:
** 	vcx2	p0, q0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx2q_u8uint8x16_tint8x16_tint:
** 	vcx2	p0, q0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx2q_u8uint8x16_tuint16x8_tint:
** 	vcx2	p0, q0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx2q_u8uint8x16_tuint8x16_tint:
** 	vcx2	p0, q0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx2qfloat16x8_tuint16x8_tint:
** 	vcx2	p0, q0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx2qfloat16x8_tfloat32x4_tint:
** 	vcx2	p0, q0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx2qfloat32x4_tuint8x16_tint:
** 	vcx2	p0, q0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx2qint64x2_tuint8x16_tint:
** 	vcx2	p0, q0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx2qint8x16_tuint8x16_tint:
** 	vcx2	p0, q0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx2quint16x8_tuint8x16_tint:
** 	vcx2	p0, q0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx2quint8x16_tint64x2_tint:
** 	vcx2	p0, q0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx2quint8x16_tint8x16_tint:
** 	vcx2	p0, q0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx2quint8x16_tuint16x8_tint:
** 	vcx2	p0, q0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx2quint8x16_tuint8x16_tint:
** 	vcx2	p0, q0, q0, #33
** 	bx	lr
*/
/*
** test_cde_vcx2qafloat16x8_tuint16x8_tint:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx2a	p0, (q[0-7]), q0, #33
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx2qafloat16x8_tfloat32x4_tint:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx2a	p0, (q[0-7]), q0, #33
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx2qafloat32x4_tuint8x16_tint:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx2a	p0, (q[0-7]), q0, #33
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx2qaint64x2_tuint8x16_tint:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx2a	p0, (q[0-7]), q0, #33
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx2qaint8x16_tuint8x16_tint:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx2a	p0, (q[0-7]), q0, #33
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx2qauint16x8_tuint8x16_tint:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx2a	p0, (q[0-7]), q0, #33
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx2qauint8x16_tint64x2_tint:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx2a	p0, (q[0-7]), q0, #33
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx2qauint8x16_tint8x16_tint:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx2a	p0, (q[0-7]), q0, #33
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx2qauint8x16_tuint16x8_tint:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx2a	p0, (q[0-7]), q0, #33
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx2qauint8x16_tuint8x16_tint:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx2a	p0, (q[0-7]), q0, #33
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx3q_u8uint8x16_tuint8x16_tuint8x16_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3q_u8uint16x8_tuint8x16_tuint8x16_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3q_u8uint8x16_tuint16x8_tuint8x16_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3q_u8uint8x16_tuint8x16_tuint16x8_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3q_u8float16x8_tfloat16x8_tfloat16x8_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3q_u8float32x4_tuint64x2_tfloat16x8_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3q_u8int8x16_tuint8x16_tuint8x16_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3q_u8uint8x16_tint8x16_tuint8x16_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3q_u8uint8x16_tuint8x16_tint8x16_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3q_u8int64x2_tuint8x16_tuint8x16_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3q_u8uint8x16_tint64x2_tuint8x16_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3q_u8uint8x16_tuint8x16_tint64x2_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3q_u8uint8x16_tint64x2_tint64x2_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3quint8x16_tuint8x16_tuint8x16_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3qfloat16x8_tfloat16x8_tfloat16x8_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3qfloat32x4_tuint64x2_tfloat16x8_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3quint16x8_tuint8x16_tuint8x16_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3quint8x16_tuint16x8_tuint8x16_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3quint8x16_tuint8x16_tuint16x8_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3qint8x16_tuint8x16_tuint8x16_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3quint8x16_tint8x16_tuint8x16_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3quint8x16_tuint8x16_tint8x16_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3qint64x2_tuint8x16_tuint8x16_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3quint8x16_tint64x2_tuint8x16_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3quint8x16_tuint8x16_tint64x2_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3quint8x16_tint64x2_tint64x2_t:
** 	vcx3	p0, q0, q0, q1, #12
** 	bx	lr
*/
/*
** test_cde_vcx3qauint8x16_tuint8x16_tuint8x16_t:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx3a	p0, (q[0-7]), q0, q1, #12
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx3qafloat16x8_tfloat16x8_tfloat16x8_t:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx3a	p0, (q[0-7]), q0, q1, #12
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx3qafloat32x4_tuint64x2_tfloat16x8_t:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx3a	p0, (q[0-7]), q0, q1, #12
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx3qauint16x8_tuint8x16_tuint8x16_t:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx3a	p0, (q[0-7]), q0, q1, #12
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx3qauint8x16_tuint16x8_tuint8x16_t:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx3a	p0, (q[0-7]), q0, q1, #12
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx3qauint8x16_tuint8x16_tuint16x8_t:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx3a	p0, (q[0-7]), q0, q1, #12
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx3qaint8x16_tuint8x16_tuint8x16_t:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx3a	p0, (q[0-7]), q0, q1, #12
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx3qauint8x16_tint8x16_tuint8x16_t:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx3a	p0, (q[0-7]), q0, q1, #12
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx3qauint8x16_tuint8x16_tint8x16_t:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx3a	p0, (q[0-7]), q0, q1, #12
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx3qaint64x2_tuint8x16_tuint8x16_t:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx3a	p0, (q[0-7]), q0, q1, #12
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx3qauint8x16_tint64x2_tuint8x16_t:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx3a	p0, (q[0-7]), q0, q1, #12
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx3qauint8x16_tuint8x16_tint64x2_t:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx3a	p0, (q[0-7]), q0, q1, #12
** 	vmov	q0, \2
** 	bx	lr
*/
/*
** test_cde_vcx3qauint8x16_tint64x2_tint64x2_t:
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L([0-9]*)
** 	vldr\.64	d(?:[01][0-4]|[0-9]), \.L\1\+8
** 	vcx3a	p0, (q[0-7]), q0, q1, #12
** 	vmov	q0, \2
** 	bx	lr
*/
