package InfixToPostfix;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Test {
     public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		File f=new File("test.txt");
                                            f.createNewFile();
                                            BufferedWriter out=new BufferedWriter(new FileWriter(f));
		Scanner s=new Scanner(System.in);
		System.out.println("请输入表达式生成个数:");	
		int n=s.nextInt();
		String ss=null;
		for(int i=0;i<n;i++)
		{
			out.write(lianxi.createxpression()+"\r\n");
		}
		out.close();
		s.close();
	}
}