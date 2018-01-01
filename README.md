# simd
Various SIMD tests

# Compilation

Compile this example using:
```
  gcc -Wall -mavx2 -o avx2_test avx2_test.c
```

# Output

avx2_test.c is used to demonstrate some use of vectorized gcc that can be CPU generic for
Intel/AVX or ARM/Neon.

Example on my laptop:
```
intel
 popcnt supported
 avx supported
 avx2 supported
eq: a[0]=31 b[0]=31 res[0]=65535
eq: a[1]=31 b[1]=30 res[1]=0
eq: a[2]=29 b[2]=29 res[2]=65535
eq: a[3]=28 b[3]=28 res[3]=65535
eq: a[4]=27 b[4]=27 res[4]=65535
eq: a[5]=26 b[5]=26 res[5]=65535
eq: a[6]=25 b[6]=25 res[6]=65535
eq: a[7]=24 b[7]=24 res[7]=65535
eq: a[8]=23 b[8]=23 res[8]=65535
eq: a[9]=22 b[9]=22 res[9]=65535
eq: a[10]=21 b[10]=21 res[10]=65535
eq: a[11]=20 b[11]=20 res[11]=65535
eq: a[12]=19 b[12]=19 res[12]=65535
eq: a[13]=18 b[13]=18 res[13]=65535
eq: a[14]=17 b[14]=17 res[14]=65535
eq: a[15]=16 b[15]=16 res[15]=65535
gt: a[0]=31 b[0]=31 res[0]=0
gt: a[1]=31 b[1]=30 res[1]=65535
gt: a[2]=29 b[2]=29 res[2]=0
gt: a[3]=28 b[3]=28 res[3]=0
gt: a[4]=27 b[4]=27 res[4]=0
gt: a[5]=26 b[5]=26 res[5]=0
gt: a[6]=25 b[6]=25 res[6]=0
gt: a[7]=24 b[7]=24 res[7]=0
gt: a[8]=23 b[8]=23 res[8]=0
gt: a[9]=22 b[9]=22 res[9]=0
gt: a[10]=21 b[10]=21 res[10]=0
gt: a[11]=20 b[11]=20 res[11]=0
gt: a[12]=19 b[12]=19 res[12]=0
gt: a[13]=18 b[13]=18 res[13]=0
gt: a[14]=17 b[14]=17 res[14]=0
gt: a[15]=16 b[15]=16 res[15]=0
add: a[0]=31 b[0]=31 res[0]=62
add: a[1]=31 b[1]=30 res[1]=61
add: a[2]=29 b[2]=29 res[2]=58
add: a[3]=28 b[3]=28 res[3]=56
add: a[4]=27 b[4]=27 res[4]=54
add: a[5]=26 b[5]=26 res[5]=52
add: a[6]=25 b[6]=25 res[6]=50
add: a[7]=24 b[7]=24 res[7]=48
add: a[8]=23 b[8]=23 res[8]=46
add: a[9]=22 b[9]=22 res[9]=44
add: a[10]=21 b[10]=21 res[10]=42
add: a[11]=20 b[11]=20 res[11]=40
add: a[12]=19 b[12]=19 res[12]=38
add: a[13]=18 b[13]=18 res[13]=36
add: a[14]=17 b[14]=17 res[14]=34
add: a[15]=16 b[15]=16 res[15]=32
xor: a[0]=31 b[0]=31 res[0]=0
xor: a[1]=31 b[1]=30 res[1]=1
xor: a[2]=29 b[2]=29 res[2]=0
xor: a[3]=28 b[3]=28 res[3]=0
xor: a[4]=27 b[4]=27 res[4]=0
xor: a[5]=26 b[5]=26 res[5]=0
xor: a[6]=25 b[6]=25 res[6]=0
xor: a[7]=24 b[7]=24 res[7]=0
xor: a[8]=23 b[8]=23 res[8]=0
xor: a[9]=22 b[9]=22 res[9]=0
xor: a[10]=21 b[10]=21 res[10]=0
xor: a[11]=20 b[11]=20 res[11]=0
xor: a[12]=19 b[12]=19 res[12]=0
xor: a[13]=18 b[13]=18 res[13]=0
xor: a[14]=17 b[14]=17 res[14]=0
xor: a[15]=16 b[15]=16 res[15]=0
min: a[0]=31 b[0]=31 res[0]=31
min: a[1]=31 b[1]=30 res[1]=30
min: a[2]=29 b[2]=29 res[2]=29
min: a[3]=28 b[3]=28 res[3]=28
min: a[4]=27 b[4]=27 res[4]=27
min: a[5]=26 b[5]=26 res[5]=26
min: a[6]=25 b[6]=25 res[6]=25
min: a[7]=24 b[7]=24 res[7]=24
min: a[8]=23 b[8]=23 res[8]=23
min: a[9]=22 b[9]=22 res[9]=22
min: a[10]=21 b[10]=21 res[10]=21
min: a[11]=20 b[11]=20 res[11]=20
min: a[12]=19 b[12]=19 res[12]=19
min: a[13]=18 b[13]=18 res[13]=18
min: a[14]=17 b[14]=17 res[14]=17
min: a[15]=16 b[15]=16 res[15]=16
max: a[0]=31 b[0]=31 res[0]=31
max: a[1]=31 b[1]=30 res[1]=31
max: a[2]=29 b[2]=29 res[2]=29
max: a[3]=28 b[3]=28 res[3]=28
max: a[4]=27 b[4]=27 res[4]=27
max: a[5]=26 b[5]=26 res[5]=26
max: a[6]=25 b[6]=25 res[6]=25
max: a[7]=24 b[7]=24 res[7]=24
max: a[8]=23 b[8]=23 res[8]=23
max: a[9]=22 b[9]=22 res[9]=22
max: a[10]=21 b[10]=21 res[10]=21
max: a[11]=20 b[11]=20 res[11]=20
max: a[12]=19 b[12]=19 res[12]=19
max: a[13]=18 b[13]=18 res[13]=18
max: a[14]=17 b[14]=17 res[14]=17
max: a[15]=16 b[15]=16 res[15]=16
```
