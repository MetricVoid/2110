/**
 * CS 2110 Spring 2020 HW1
 * Part 2 - Coding with bases
 *
 * @author Zhaoran Ma
 *
 * Global rules for this file:
 * - You may not use more than 2 conditionals per method. Conditionals are
 *   if-statements, if-else statements, or ternary expressions. The else block
 *   associated with an if-statement does not count toward this sum.
 * - You may not use more than 2 looping constructs per method. Looping
 *   constructs include for loops, while loops and do-while loops.
 * - You may not use nested loops.
 * - You may not declare any file-level variables.
 * - You may not use switch statements.
 * - You may not use the unsigned right shift operator (>>>)
 * - You may not write any helper methods, or call any other method from this or
 *   another file to implement any method.
 * - The only Java API methods you are allowed to invoke are:
 *     String.length()
 *     String.charAt()
 * - You may not invoke the above methods from string literals.
 *     Example: "12345".length()
 * - When concatenating numbers with Strings, you may only do so if the number
 *   is a single digit.
 *
 * Method-specific rules for this file:
 * - You may not use multiplication, division or modulus in any method, EXCEPT
 *   decimalStringToInt
 * - You may declare exactly one String variable each in intToOctalString and
 *   and BinaryStringToHexString.
 */
public class Bases
{
    /**
     * Convert a string containing ASCII characters (in binary) to an int.
     * You do not need to handle negative numbers. The Strings we will pass in will be
     * valid binary numbers, and able to fit in a 32-bit signed integer.
     *
     * Example: binaryStringToInt("111"); // => 7
     */
    public static void main(String[] args) {
        System.out.print(binaryStringToHexString("1011"));
    }
    public static int binaryStringToInt(String binary)
    {
        int result = 0;
        for (int i = 0; i< binary.length(); i++) {
            int ch = binary.charAt(i) - '0';
            result = (result << 1) + ch;
        }
        return result;
    }

    /**
     * Convert a string containing ASCII characters (in decimal) to an int.
     * You do not need to handle negative numbers. The Strings we will pass in will be
     * valid decimal numbers, and able to fit in a 32-bit signed integer.
     *
     * Example: decimalStringToInt("123"); // => 123
     *
     * You may use multiplication, division, and modulus in this method.
     */
    public static int decimalStringToInt(String decimal)
    {
        int result = 0;
        for (int i = 0; i< decimal.length(); i++) {
            int ch = decimal.charAt(i) - '0';
            result = result * 10 + ch;
        }
        return result;

    }

    /**
     * Convert a string containing ASCII characters (in hex) to an int.
     * The input string will only contain numbers and uppercase letters A-F.
     * You do not need to handle negative numbers. The Strings we will pass in will be
     * valid hexadecimal numbers, and able to fit in a 32-bit signed integer.
     *
     * Example: hexStringToInt("A6"); // => 166
     */
    public static int hexStringToInt(String hex)
    {
        int result = 0;
        for (int i = 0; i< hex.length(); i++) {
            int digit;
            char ch = hex.charAt(i);
            if (ch - '9' <= 0) {
                digit = ch - '0';
            } else {
                digit = ch - 'A' + 10;
            }
            result = (result << 4) + digit;
        }
        return result;
    }

    /**
     * Convert a int into a String containing ASCII characters (in octal).
     * You do not need to handle negative numbers.
     * The String returned should contain the minimum number of characters necessary to
     * represent the number that was passed in.
     *
     * Example: intToOctalString(10); // => "12"
     *
     * You may declare one String variable in this method.
     */
    public static String intToOctalString(int octal)
    {
        String result = "";
        int reminder;
        while (octal != 0) {
            reminder = octal - ((octal >> 3)<<3);
            octal = octal >> 3;
            result = (char) (reminder+'0') + result;
        }
        return (result == ""?"0":result);
    }

    /**
     * Convert a String containing ASCII characters representing a number in binary into 
     * a String containing ASCII characters that represent that same value in hexadecimal.
     * The output string should only contain numbers and uppercase letters A-F.
     * You do not need to handle negative numbers.
     * The String returned should contain the minimum number of characters necessary to
     * represent the number that was passed in.
     * The length of all the binary strings passed in will be of size 16.
     *
     * Example: binaryStringToHexString("0010111110100001"); // => 2FA1
     *
     * You may declare one String variable in this method.
     */
    public static String binaryStringToHexString(String binary)
    {
        int digit;
        char ch;
        String result = "";
        for (int i = 0; i< binary.length(); i += 4){
            digit = 0;
            digit = ((binary.charAt(i)-'0') << 3) +
                ((binary.charAt(i+1)-'0') << 2) +
                ((binary.charAt(i+2)-'0') << 1) +
                ((binary.charAt(i+3)-'0') << 0);
            if (digit > 9) {
                ch = (char)(digit - 10 +'A');
            } else {
                ch = (char) (digit+'0');
            }
            result += ch;
        }
        return result;
    }
}
