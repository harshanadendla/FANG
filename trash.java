public class trash
{
    static void permutation(String a)
    {
        permutation(a,"");
    }
    static void permutation(String a,String b)
    {
        if(a.length()==0)
        {
            System.out.println(b);
        }
        else
        {
            for(int i=0;i<a.length();i++)
            {
                String rem=a.substring(0,i)+a.substring(i+1);
                System.out.println("rem "+ rem);
                permutation(rem,b+a.charAt(i));
            }
        }
    }

    public static void main(String []args)
    {
        String a="abc";
        permutation(a);
    }
}