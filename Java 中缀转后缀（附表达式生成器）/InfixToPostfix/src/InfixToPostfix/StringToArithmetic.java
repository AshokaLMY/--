package InfixToPostfix;

import java.util.Stack;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.ArrayList;
import java.util.HashSet;
import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
public class StringToArithmetic {
     private StringToArithmetic() {}
     public static String infixToSuffix(String infix) {
         Stack<Character> stack = new Stack<Character>();
         String suffix = "";
         int length = infix.length();
         for (int i = 0; i < length; i++) {
             Character temp;
             char c = infix.charAt(i);
             switch (c) {
                 // 忽略空格
                case ' ':
                   break;
                 // 碰到'('，push到栈
                 case '(':
                     stack.push(c);
                     break;
                // 碰到'+''-'，将栈中所有运算符弹出，送到输出队列中
                 case '+':
                 case '-':
                     while (stack.size() != 0) {
                         temp = stack.pop();
                         if (temp == '(') {
                             stack.push('(');
                             break;
                         }
                         suffix +=temp;
                     }
                     stack.push(c);
                     break;
                 // 碰到'*''/'，将栈中所有乘除运算符弹出，送到输出队列中
                 case '*':
                 case '/':
                     while (stack.size() != 0) {
                         temp = stack.pop();
                        if (temp == '(' || temp == '+' || temp == '-') {
                             stack.push(temp);
                             break;
                         } 
                        else {
                        	 suffix +=temp;
                        }
                     }
                     stack.push(c);
                     break;
                 // 碰到右括号，将靠近栈顶的第一个左括号上面的运算符全部依次弹出，送至输出队列后，再丢弃左括号
                case ')':
                     while (stack.size() != 0) {
                         temp = stack.pop();
                         if (temp == '(')
                             break;
                         else
                         suffix +=temp;
                     }
                     break;
                case ';':
                	break;
                 //如果是数字，直接送至输出序列
                 default:
                    suffix += c;
            }
         }
 
         //如果栈不为空，把剩余的运算符依次弹出，送至输出序列。
         while (stack.size() != 0) {
        	 suffix +=stack.pop();
        }
         return suffix;
}
     
     public static boolean isNumber(String str)
     {
     Pattern p=Pattern.compile("\\d+||(\\d+\\.\\d+)");
     Matcher n=p.matcher(str);
     if(!n.matches())
    	 return false;
     return true;
     }
     
     
	public static void main(String[] args)throws Exception{
		// TODO Auto-generated method stub
	        File f=new File("test.txt");
	        FileReader fr=new FileReader(f);
	        BufferedReader br=new BufferedReader(fr);
	        String str =null;
	        String s=null;
	        int i=1;
                while ((str=br.readLine()) !=null)
                {
                	s=str.substring(0,str.length()-1);                    
                	 System.out.println(StringToArithmetic.infixToSuffix(str));
                	i++;
                }
                br.close();
          }
}