import java.io.*;
import java.net.*;
import java.util.*;

public class RodCutting
{
static Scanner io=new Scanner(System.in);
public static long RodCuttingBruteForce(int n,int P[])
{
	if(n==0)
		return 0;
	long cut=-999999;
	for(int i=0;i<n;i++)
		cut=Math.max(cut,P[i]+RodCuttingBruteForce(n-i,P));
	return cut;
}
public static void main(String ard[])throws Exception
{
	File file = new File("lp.txt"); 
    long startTime=0,duration=0;
	FileWriter fw=new FileWriter(file);
	int n=io.nextInt();
	int p[]=new int[10];
	for(int i=0;i<n;i++)
		p[i]=(int)(Math.random()*50);
	for(int j=0;j<n;j++)
		fw.write(""+io.nextInt()+" ");
  	fw.close();
	//file.close();
	File file1 = new File("lp.txt"); 
  	Scanner br=new Scanner(file1);
  String str; 
  while (br.hasNextLine()) 
  {
	int n1=Integer.parseInt(br.next());
	startTime = System.nanoTime();
	//RodCuttingBruteForce(n1,p);
    int i=10000;
    while(i--<0)
	duration = System.nanoTime();
	System.out.println("N:"+n1+"   "+startTime+duration);
  } 
}
}