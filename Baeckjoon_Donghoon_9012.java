import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		sc.nextLine();
		String vps;
		Stack s = new Stack();
		int count=0;
		char temp;
		for(int i=0; i<T; i++)
		{
			count=0;
			vps = sc.nextLine();
			for(int j=0; j<vps.length(); j++)
			{
				temp = vps.charAt(j);
				if(temp=='(')
				{
					s.push(temp);
				}
				else
				{
					count++;
					if(!s.empty())
					{
					s.pop();
					count--;
					}
					else
					{
						System.out.println("NO");
						break;
					}
				}
			}
			
			if(!s.empty())
			{
				System.out.println("NO");
				while(!s.empty())
					s.pop();
				continue;
			}
			else if(count==0)
			System.out.println("YES");
		}
		
	}
}
