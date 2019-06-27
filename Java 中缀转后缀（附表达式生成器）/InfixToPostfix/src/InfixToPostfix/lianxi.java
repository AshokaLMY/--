package InfixToPostfix;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.HashSet;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class lianxi {
     public static boolean isNumber(String str)
    {
    Pattern p=Pattern.compile("\\d+||(\\d+\\.\\d+)");
    Matcher n=p.matcher(str);
    if(!n.matches())
   	 return false;
    return true;
    }
    
    public static boolean getNumberStringFromList(ArrayList<Character>list)
    {
    if(list!=null) {
   	 StringBuffer s=new StringBuffer();
   	 for(Character c:list)
   		 s.append(c);
   	 boolean r=isNumber(s.toString());
   	 if(!r)
   	 {
			 return false;
   	 }
   	 return r;
    }
    return false;
    }

    public static boolean fun(String str)
    {
   	 HashSet<Character>os=new HashSet<>();
   	 os.add('-');
   	 os.add('+');
   	 os.add('/');
   	 os.add('*');
   	 ArrayList<Character>d=new ArrayList<>();
   	 int cn=0;
   	 int length = str.length();
   	 for(int j=0;j<length;j++)
   	 {
   		 char c = str.charAt(j);
   		 if(Character.isDigit(c)||c=='.')
   			 d.add(c);
   		 else
   		 {
   			 if(d.size()>0)
   			 {
    				boolean r=getNumberStringFromList(d);
    			                      if(r)
    				     d.clear();
    			                      else 
    				          return false;
   		                      }
   		                      if(c=='+'||c=='*'||c=='/')
   		                     {
   		                                if(j==0||j==(length-1)||os.contains(str.charAt(j+1))||str.charAt(j+1)==')')
   		                                {
   			                    return false;
   		                                 }
   		                      }
   		                     else if(c=='-')
   		                      {
   			          if(j==(length-1)||os.contains(str.charAt(j+1))||str.charAt(j+1)==')')
   			          {	
   			                   return false;
   			            }
   		                      }
   		                     else if(c=='(')
   		                      {
   			         cn++;
   			          if(j==(length-1)||str.charAt(j+1)=='+'||str.charAt(j+1)=='*'||str.charAt(j+1)=='/'|str.charAt(j+1)==')'||(j!=0&&Character.isDigit(str.charAt(j-1))))
   		                                  { 
   				return false;
                                                                             }
   		                      }
   		                       else if(c==')')
   		                       {
   			        cn--;
   			        if(j==0||j<(length-1)&&str.charAt(j+1)=='('||cn<0)
   			       {
   				 return false; 
   			       }
   		                     }
   		                     else if(c!=';')
   		                     {
		                                  return false;
   		                      }
   	                       }	
                      }
   	 if(d.size()>0)
                       {
		boolean r=getNumberStringFromList(d);
		if(r)
		            d.clear();
		else 
		                return false; 
	}
   	 if(cn!=0)
   	             return false;
   	 return true;	
    }
    
	public static String createxpression()
	{
		StringBuffer str=new StringBuffer();
		char Op[]= {'+','-','*','/'};
		int length=(int)(Math.random()*10)+2;
		boolean d=false;
		int bc=0;
	    for(int i=0;i<length;i++)
	    {
		   if(d)
		   {
			   d=false;
			   double num=Math.random()*10;
			   while(num==0.0)
				   num=Math.random()*10;
			   str.append(num);
		   }
		   else  str.append((int)(Math.random()*10)); 
		   int t=bc;
		   for(int j=0;j<t;j++)
		   {
			   if(Math.random()*5>2)
			   {
				   bc--;
				   str.append(')');
			   }
		   }
		   int op=(int)(Math.random()*4);
		   str.append(Op[op]);
		   if(op==3)
		   d=true;
		   if(Math.random()*2>1)
		   {
			   str.append('('); 
			   bc++;
			   str.append((int)(Math.random()*10)); 
			   op=(int)Math.random()*4;
			   str.append(Op[op]);
			   if(op==3)
				   d=true;
		   }
	    }
	    if(d)
		   {
			   d=false;
			   double num=Math.random()*10;
			   while(num==0.0)
				   num=Math.random()*10;
			   str.append((int)num); 
		   }
	    else  str.append((int)(Math.random()*10));
	    for(int i=0;i<bc;i++)
	    {
	    	str.append(')');
	    }
	    str.append(';');
		return str.toString();
	}
	 	
}