/*
 *     x x x x x x x x x x x x x x x x
 *     1 2 3 4 5 6 7 8 9 1 1 1 1 1 1 1
 *                       0 1 2 3 4 5 6
 *  
 * y1  E S I S T E I N Z W E I D R E I
 * y2  V I E R F Ü N F S E C H S I E B
 * y3  A C H T N E U N Z E H N E L F E
 * y4  Z W Ö L F   N D W A N Z I G   N
 * y5  U H R E I N S Z W E I D R E I
 * y6  V I E R F Ü N F S E C H S I E B 
 * y7  A C H T N E U N Z E H N E L F E
 * y8  Z W Ö L F U N D W A N Z I G   N
 * y9  D R E I ß I G V I E R Z I G   I
 * y10 F Ü N F Z I G T O R T E L L O N
 */
 
#include "Wordclock_Layout.h"

const int wordES[]=      {X1Y1, X2Y1};
const int wordIST[]=    {X3Y1, X4Y1, X5Y1};
const int wordhUhr[]=   {X1Y5, X2Y5, X3Y5};

const int wordhEin[] =      {X6Y1, X7Y1, X8Y1};
const int wordhZwei[] =   {X9Y1, X10Y1, X11Y1, X12Y1};
const int wordhDrei[] =   {X13Y1, X14Y1, X15Y1, X16Y1};
const int wordhVier[] =   {X1Y2, X2Y2, X3Y2, X4Y2};
const int wordhFuenf[] =    {X5Y2, X6Y2, X7Y2, X8Y2};
const int wordhSechs[] =    {X9Y2, X10Y2, X11Y2, X12Y2, X13Y2};
const int wordhSieben[] =   {X13Y2, X14Y2, X15Y2, X16Y2, X16Y3, X16Y4};
const int wordhAcht[] =   {X1Y3, X2Y3, X3Y3, X4Y3};
const int wordhNeun[] =   {X5Y3, X6Y3, X7Y3, X8Y3};
const int wordhZehn[] =   {X9Y3, X10Y3, X11Y3, X12Y3};
const int wordhElf[] =      {X13Y3, X14Y3, X15Y3};
const int wordhZwoelf[] =   {X1Y4, X2Y4, X3Y4, X4Y4, X5Y4};

const int wordmEins[] =   { X4Y5, X5Y5, X6Y5, X7Y5};
const int wordmEin[] =      {X5Y5, X6Y5, X7Y5};
const int wordmZwei[] =   {X8Y5, X9Y5, X10Y5, X11Y5};
const int wordmDrei[] =   {X12Y5, X13Y5, X14Y5, X15Y5};
const int wordmVier[] =   {X1Y6, X2Y6, X3Y6, X4Y6};
const int wordmFuenf[] =    {X5Y6, X6Y6, X7Y6, X8Y6};
const int wordmSechs[] =    {X9Y6, X10Y6, X11Y6, X12Y6, X13Y6};
const int wordmSech[] =   {X9Y6, X10Y6, X11Y6, X12Y6};
const int wordmSieben[] =   {X13Y6, X14Y6, X15Y6, X16Y6, X16Y7, X16Y8};
const int wordmSieb[] =   {X13Y6, X14Y6, X15Y6, X16Y6};
const int wordmAcht[] =   {X1Y7, X2Y7, X3Y7, X4Y7};
const int wordmNeun[] =   {X5Y7, X6Y7, X7Y7, X8Y7};
const int wordmZehn[] =   {X9Y7, X10Y7, X11Y7, X12Y7};
const int wordmElf[] =      {X13Y7, X14Y7, X15Y7};
const int wordmZwoelf[] =   {X1Y8, X2Y8, X3Y8, X4Y8};
const int wordmZwanzig[] =    {X9Y7, X9Y8, X10Y8, X11Y8, X12Y8, X13Y8, X14Y8};
const int wordmDreissig[] = {X1Y9, X2Y9, X3Y9, X4Y9, X5Y9, X6Y9, X7Y9};
const int wordmVierzig[] =    {X8Y9, X9Y9, X10Y9, X11Y9, X12Y9, X13Y9, X14Y9};
const int wordmFuenfzig[] = {X1Y10, X2Y10, X3Y10, X4Y10, X5Y10, X6Y10, X7Y10};

const int wordmUnd[] =    {X7Y7, X7Y8, X8Y8};
const int wordmNeunUnd[] =    {X6Y8, X7Y8, X8Y8};

const int Tortelloni[] =    {X8Y10, X9Y10, X10Y10, X11Y10, X12Y10, X13Y10, X14Y10, X15Y10, X16Y10};
