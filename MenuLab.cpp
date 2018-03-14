﻿//   M e n u   L a b   p r o g r a m   t o   m a n a g e   a n d   r e d e e m   p o i n t s   f o r   m i l k   p u r c h a s e s 
 
//   M a t t h e w   N o e l 
 
 //   2 / 7 / 2 0 1 8 
 
 
 
 //#include "stdafx.h" 
 
 #include <iostream> 
 
 
 
 using namespace std; 
 
 
 
 //   P r o t o t y p e s 
 
 char displayMenu();
 
 
 
 int main() {
 
 	 //   D e c l a r i n g   v a r i a b l e s 
 
         char option;
 
         int points, money = 0;
 
 
 
 	 cout << " W e l c o m e   t o   t h e   g r o c e r y   s t o r e ! " << endl; 
 
 	 cout <<   " H e r e   y o u   c a n   g e t   1   p o i n t   p e r   h a l f - g a l l o n   o f   m i l k   y o u   b u y ,   t h e n   r e d e e m   5   o f   t h o s e   p o i n t s   f o r   $ 1 ! "   <<   endl   <<   " H a v e   f u n ! "   <<  endl; 
 
 
 
 	 //   M e n u   l o o p   t h a t   e x e c u t e s   a t   l e a s t   o n c e 
 
 	 do { 
 
                 option = displayMenu();
 
 
 
 	 	 switch(option){
 
 
 
 	 	 	 //   B u y   a   g a l l o n 
 
 	 	 	 case   'G' : 
 
 	 	 	 case   'g' : 
 
                                 points += 2;
 
 	 	 	 	 cout << " Y o u ' v e   e a r n e d   2   p o i n t s ! " << endl; 
 
 	 	 	 	 break; 
 
 
 
 	 	 	 //   B u y   h a l f - g a l l o n 
 
 	 	 	 case 'H': 
 
 	 	 	 case 'h': 
 
 	 	 	 	 points += 1; 
 
 	 	 	 	 cout << " Y o u ' v e   e a r n e d   1   p o i n t ! "   <<   endl; 
 
 	 	 	 	 break; 
 
 
 
 	 	 	 //   R e d e e m   c o u p o n 
 
 	 	 	 c a s e   ' R ' : 
 
 	 	 	 c a s e   ' r ' : 
 
 	 	 	 	 i f   ( p o i n t s   > =   5 )   { 
 
 	 	 	 	 	 p o i n t s   - =   5 ; 
 
 	 	 	 	 	 m o n e y   + =   1 ; 
 
 	 	 	 	 	 c o u t   < <   " Y o u ' v e   r e d e e m e d   5   p o i n t s   f o r   $ 1 ! "   < <   e n d l ; 
 
 	 	 	 	 }   e l s e   { 
 
 	 	 	 	 	 c o u t   < <   " Y o u   n e e d   a t   l e a s t   f i v e   p o i n t s   t o   r e d e e m   a   c o u p o n ! "   < <   e n d l ; 
 
 	 	 	 	 } 
 
 	 	 	 	 b r e a k ; 
 
 
 
 	 	 	 c a s e   ' Q ' : 
 
 	 	 	 c a s e   ' q ' : 
 
 	 	 	 	 b r e a k ; 
 
 
 
 	 	 	 d e f a u l t : 
 
 	 	 	 	 c o u t   < <   " P l e a s e   s e l e c t   a   v a l i d   o p t i o n "   < <   e n d l ; 
 
 	 	 } 
 
 
 
 	 }   w h i l e   ( o p t i o n   ! =   ' q '   & &   o p t i o n   ! =   ' Q ' ) ; 
 
 
 
 	 c o u t   < <   " Y o u   e n d e d   w i t h   "   < <   p o i n t s   < <   "   p o i n t s   a n d   "   < <   m o n e y   < <   "   d o l l a r s ! "   < <   e n d l   < <   e n d l ; 
 
 
 
 	 s y s t e m ( " p a u s e " ) ; 
 
 	 r e t u r n   0 ; 
 
 } 
 
 
 
 / /   D i s p l a y   m e n u   f u n c t i o n 
 
 c h a r   d i s p l a y M e n u ( )   { 
 
 	 c h a r   c ; 
 
 
 
 	 c o u t   < <   e n d l   < <   " W h a t   w o u l d   y o u   l i k e   t o   d o ? "   < <   e n d l   < <   e n d l ; 
 
 
 
 	 c o u t   < <   " [ G ]     P u r c h a s e   o n e   g a l l o n   o f   m i l k "   < <   e n d l ; 
 
 	 c o u t   < <   " [ H ]     P u r c h a s e   o n e - h a l f   g a l l o n   o f   m i l k "   < <   e n d l ; 
 
 	 cout << "[R]  Redeem coupon" << endl; 
 
 	 cout << "[Q]  Quit" << endl; 
 
 
 
 	 cout << endl << "I choose to: "; 
 
 
 
 	 cin >> c; 
 
 
 
 	 cout << endl; 
 
 
 
 	 return c; 
 
 } 
 
 
 
 
