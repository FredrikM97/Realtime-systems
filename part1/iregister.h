//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.

#ifndef lab0_iregister_h
#define lab0_iregister_h

/**
 *  iRegister
 *  An iRegister is a structure which represents an 32-bit register and
 *  is equipped with standard operations to modify and display them.
 */ 
typedef struct{
    int content;
} iRegister;

/**
 *  Bellow you find the declarations for the functions to modify and display the
 *  memory content of a iRegister data structure. Before each declaration, a brief 
 *  description about what the function shall do is given. 
 *  Later in this file, the documentation for the resetBit function is given. 
 *  Students should follow that format.
 */ 

/** 
 @brief Description: resets all the bits of the iRegister (to 0)
 @return void
 @param r is a pointer to a memory location of a iRegister data structure
 @pre iRegister != Null
 @post After resetAll(r) the iRegister is set to 0
 
 Properties:
 
 test-cases: 
 **/
void resetAll(iRegister *);
/** 
 @brief sets the i'th bit of the iRegister (to 1)
 @return void
 @param r is a pointer to a memory location of a iRegister data structure
 @param i Is i'th bit of the iRegister to be reset
 @pre 0 <= i < 32 and iRegister != Null
 @post After setBit(i,r) the i'th bit of iRegister is set to 1
 
 Properties:
 
 test-cases: 

**/
void setBit(int, iRegister *);

/** 
 @brief sets all the bits of the iRegister (to 1)
 @return void
 @param r is a pointer to a memory location of a iRegister data structure
 @pre iRegister != Null
 @post After setAll(r) all bits in iRegister is set to one
 
 Properties:
 
 test-cases: 

**/
void setAll(iRegister *);

/** 
 @brief returns the i'th bit of the iRegister as an integer (1 if it is set, or 0 otherwise)
 @return bit in i'th position 
 @param r is a pointer to a memory location of a iRegister data structure
 @param i Is i'th bit of the iRegister to be reset
 @pre 0 <= i < 32 and iRegister != Null
 @post After getBit(i,r) return i'th bit in iRegister
 
 Properties:
 
 test-cases: 

**/
int getBit(int, iRegister *);

/** 
 @brief set the first pos and the second a value of four bits of the nipple to the iRegsiter
 @return bit in i'th position 
 @param r is a pointer to a memory location of a iRegister data structure
 @param i Is i'th bit of the iRegister to be reset
 @pre 0 <= Pos < 32 and iRegister != Null
 @post After assignNibble(i,i,r) change the first four or four last in register
 
 Properties:
 
 test-cases: 

**/
void assignNibble(int, int, iRegister *);

/** 
 @brief Get the first (for pos=1) or the second (for pos=2) four bits of iRegsiter
 @return bit in i'th position 
 @param r is a pointer to a memory location of a iRegister data structure
 @param i Is i'th bit of the iRegister to be reset
 @pre 0 <= i < 32 and iRegister != Null
 @post After getNibble(i,r) change the first four or four last in register
 
 Properties:
 
 test-cases: 

**/
int getNibble(int, iRegister *);

/** 
 @brief returns a pointer1 to an array of 32 characters, with each character 
 *  representing the corresponding bit of the iRegister, i.e., if the bit is set,
 *  then the character is "1" (ASCII char with code 49), or otherwise is "0" 
 *  (ASCII char with code 48)
 @return bit in i'th position 
 @pre iRegister != Null
 @post 
 
 Properties:
 
 test-cases: 

**/
char *reg2str(iRegister);

/** 
 @brief shifts all the bits of the iRegister to the right by n palces (appends 0 
 *  from the left)
 @return bit in i'th position 
 @param r is a pointer to a memory location of a iRegister data structure
 @param i Is i'th bit of the iRegister to be reset
 @pre 0 <= i < 32 and iRegister != Null
 @post After assignNibble(i,i,r) change the first four or four last in register
 
 Properties:
 
 test-cases: 

**/
void shiftRight(int, iRegister *);

/** 
 @brief shifts all the bits of the iRegister to the left by n palces (appends 0 
 *  from the right)
 @return bit in i'th position 
 @param r is a pointer to a memory location of a iRegister data structure
 @param i Is i'th bit of the iRegister to be reset
 @pre 0 <= i < 32 and iRegister != Null
 @post After assignNibble(i,i,r) change the first four or four last in register
 
 Properties:
 
 test-cases: 

**/
void shiftLeft(int, iRegister *);


/** @brief Resets the i'th bit of the iRegister (to 0)
 *
 *  @param i Is i'th bit of the iRegister to be reset
 * 
 *  @param r A pointer to a memory location of a iRegister data structure.
 * 
 *  @return void
 * 
 *  Pre-condition: 0 <= i < 32 and iRegister != Null
 * 
 *  Post-condition: after reset(i, r) the i'th bit of iRegister is 0, all other 
 *  bits remain unchanged
 *  properties: 
 *  after resetBit(i, r),  getBit(i, r) = 0
 *  if getBit(i, r) == 0 then  
 *    getBit(j, r) returns the same value for all 
 *  0 <= j < 32 and j <> i before and after resetBit(i, r)
 * 
 *  test-cases: 
 *  1,2,3. Allocate memory to an iRegister r
 *  first do resetAll(&r),
 *  then set the i'th bit of &x by setBit(i, &r) for i = 0, 15 and 23 and then
 *  display the result after each and every call by 
 *    printf("%s",reg2str(r)) 
 */
void resetBit(int, iRegister *);

#endif
