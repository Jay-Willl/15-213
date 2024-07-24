/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */
#endif

// 1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
/*
0001 0001 1110
0011 1100 0011
     0000 0010
     1111 1101
          1101
          0010
*/
int bitXor(int x, int y)
{
    return ~(~(~x & y) & ~(x & ~y));
}

/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
/*
111...111
111...110
011...111
 */
int tmin(void)
{
    return (~0) << 31;
}

// 2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
/*
x == TMax -> ~xor(mask, x) == 111...111
x != TMax -> ~xor(mask, x) == 000...000
*/
int isTmax(int x)
{
    int mask = 0x7fffffff;
    int xored = ((x & ~mask) | (~x & mask));
    return !xored;

    // return !!((x + 1) >> 31);
}

/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
/*
IF x is allOddBits -> xor(masked, mask) == 000...000
IF x is not allOddBits -> xor(masked, mask) != 000...000
*/
int allOddBits(int x)
{
    int mask = 0xAAAAAAAA;
    int masked = mask & x;
    int xored = ((masked & ~mask) | (~masked & mask));
    return !xored;
}

/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
/*
IF x == TMin DO return TMin
IF x != TMin DO return ~x + 1
*/
int negate(int x)
{
    return ~x + 1;
}

// 3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
/*
0x00110000 0x00111001

0x ffffffdx
0x 0000003x
0x10000000x

0b0000 || 0b0111 || 0b1000 || 0b1001
lower_x >> 3 == 0 || ~xor(lower_x >> 1, 0b011) == 0 (xor(lower_x, 0b1000) == 0 || xor(lower_x, 0b1001) == 0)

111 -> 1
110 -> 0
*/
int isAsciiDigit(int x)
{
    int upper_mask = 0xfffffff0;
    int upper_res = x & upper_mask;
    upper_res = !(upper_res ^ 0x00000030);
    int lower_x = x + 0xffffffd0;
    // printf(">>>\n");
    // printf("%x\n", x);
    // printf("%x\n", upper_res);
    // printf("%x\n", lower_x);
    // printf("%x\n", lower_x >> 3);
    // printf("%x\n", (lower_x >> 1));
    // printf("%x\n", !(((lower_x >> 1) ^ 0x3)) ^ 0x7);
    // printf("<<<\n");

    return upper_res & (
        !(lower_x >> 3) |
        !((((lower_x >> 1) ^ 0x3)) ^ 0x7)
    );
}

/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
/*
IF x != 0 DO return y
IF x == 0 DO return z

if x != 0 -> xor(x, 0) != 0 -> !!xor(x, 0) == 1 -> 
if x == 0 -> xor(x, 0) == 0 -> !!xor(x, 0) == 0 -> 

>>>
return x_is_not_0 & y + x_is_0 & z
>>>
x_is_0 :
    x == 0 DO return 111...111
    x != 0 DO return 000...000
x_is_not_0:
    x == 0 DO return 000...000
    x != 0 DO return 111...111
*/
int conditional(int x, int y, int z)
{
    int x_is_not_0 = (!!(x ^ 0)) << 31 >> 31;
    int x_is_0 = ~x_is_not_0;
    // printf("%x\n", x_is_0);
    // printf("%x\n", x_is_not_0);
    // printf("%x\n", x_is_not_0 & y);
    // printf("%x\n", x_is_0 & z);
    // printf("%x\n", x_is_not_0 & y + x_is_0 & z);
    // printf("%x\n", (x_is_not_0 & y) + (x_is_0 & z));
    return (x_is_not_0 & y) + (x_is_0 & z);
}

/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
/*
IF x <= y DO return 1
IF x > y DO return 0

>>>
x <= y -> x - y <= 0
>>>
IF y != TMin -> OK
IF y == TMin -> x - y == x + y -> NOT OK
>>>
IF x == y -> !xor(x, y) == 1 DO return 1

IF y == TMin -> xor(y, TMin) == 0 DO return 0
IF y != TMin -> xor(y, TMin) != 0 DO return 0

IF x < y -> arith_res == 111...111 DO return 1 
IF x > y -> arith_res == 000...000 DO return 0

*/
int isLessOrEqual(int x, int y)
{
    int arith_res = (x + (~y + 1)) >> 31;
    return !(x ^ y) |
        // !!(y ^ 0x80000000) |
        !!arith_res;
}

// 4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
/*
IF x == 0 DO return 1
IF x != 0 DO return 0

IF x == 0 DO return 0 (000...000) + 1
IF x != 0 DO return -1 (111...111) + 1

IF x == 0 -> x | (~x + 1) >> 000...000
IF x != 0 -> x | (~x + 1) >> 111...111
*/
int logicalNeg(int x)
{
    int result = (x | (~x + 1)) >> 31;

    return result + 1;
}

/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
/*
>>>
-5
1 | 011
1 | 1111011
1   1110110

-1
1
1 | 1111111

-2
10
1 | 1111110

0
0
0 | 0000000

1
01
0 | 0000001

TMin
TMin
1 | 0000000

TMax
TMax
0 | 1111111

对负数来说, 统计第一个零出现的位置, 再加上sign bit
对正数来说, 统计第一个壹出现的位置, 再加上sign bit

为了normalize两种情况, 使用XOR
因为是统计第一个非consecutive bit的位置, 那么目标位的前一位总会被设为1
因此
11111001
11110010
--------XOR
00001011

00000000
00000000
--------XOR
00000000

10000000
00000000
--------XOR
10000000


*/
int howManyBits(int x)
{
    int truncated = x ^ (x << 1);

    int upper = truncated >> 16;
    int res_16 = !!(upper) << 4;

    upper = truncated >> 24;
    int res_8 = !!(upper) << 3;

    upper = truncated >> 28;
    int res_4 = !!(upper) << 2;

    upper = truncated >> 30;
    int res_2 = !!(upper) << 1;

    upper = truncated >> 31;
    int res_1 = !!(upper);

    return res_16 + res_8 + res_4 + res_2 + res_1 + 1;
}
/*

*/

// float
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
/*
sign | exp | frac
  1  |  8  |  23
*/
unsigned floatScale2(unsigned uf)
{
    unsigned sign = (uf & 0x80000000) >> 31;
    unsigned exp = (uf & 0x7f800000) >> 23;
    unsigned frac = uf & 0x007fffff;

    if (exp == 0xff) {
        return uf;
    } else if (exp == 0x0) {
        return (uf << 1 ) | (sign << 31);
    } else {
        exp += 1;
    }

    return (sign << 31) + (exp << 23) + frac;
}

/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
/*
sign | exp | frac
  1  |  8  |  23
*/
int floatFloat2Int(unsigned uf)
{
    int sign = (uf >> 31) && 0x1;
    unsigned exp = (uf & 0x7f800000) >> 23;
    int E = exp - 127;
    unsigned frac = uf & 0x007fffff;
    
    if (E < 0) {
        return 0;
    } else if (E >= 31) {
        return 0x80000000u;
    } else {
        frac = frac | (1 << 23);
        if (E < 23) {
            frac = frac >> (23 - E);
        } else {
            frac = frac << (E - 23);
        }
    }

    if (sign) {
        return -frac;
    } else {
        return frac;
    }
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
/*
sign | exp | frac
  1  |  8  |  23

smallest positive denorm float: 2^(-126) * 2^(-23) = 2^(-149) | 0 00000000 000...001
biggest positive denorm float: 2^(-126) * (1 - 2^(-23)) < 2^(-126)
smallest positive norm float: 2^(-126) * 1 = 2^(-126) | 0 00000001 000...000
biggest positive norm float: 2^(127) * (2 - 2^(-23)) < 2^128
*/
unsigned floatPower2(int x)
{
    if (x < -149) {
        return 0;
    } else if (x < -126) {
        // denorm zone
        return 0x1 << (x - (-149));
    } else if (x < 128) {
        // norm zone
        return (x - (-127)) << 23;
    } else {
        return 0xff << 23;
    }
}
