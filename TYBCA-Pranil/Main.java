import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try {
           /*
           
            int max = 5;
            Scanner sc = new Scanner(System.in);
            int i, j, n;
            int bt[] = new int[max];
            int at[] = new int[max];
            int wt[] = new int[max];
            int tat[] = new int[max];
            int temp[] = new int[max];
            float awt = 0, atat = 0;

            System.out.println("Enter the number of processes: ");
            n = sc.nextInt();  
            System.out.println("Enter the Burst of the processes: ");
            for(int a =0 ; a < bt.length;a++){
            bt[a]=sc.nextInt();
            }
            //for(int a =0 ; a < bt.length;a++){
           // System.out.println(bt[a]);
           // }
            for ( int obj : bt){
            System.out.println(obj);
            }
           */
          
           Scanner sc = new Scanner(System.in);
           int pid[]=new int[15];
                       int bt[]=new int[15];
                       int n ;
                       System.out.println("Enter the Number of Process");
                       n=sc.nextInt();
                        System.out.println("Enter the Process Id of all The Process");
                      for(int a = 0 ;a<n;a++)
                       pid[a]=sc.nextInt();
                        System.out.println("Enter the Burst Time of all The Process");
                       
                         for(int a = 0 ;a<n;a++)
                       bt[a]=sc.nextInt();
                       
                       int i;
                       int wt[]=new int[n];
                       wt[0]=0;
                       
                       
                       
                       for(i=1;i<n;i++){
                       wt[i]=bt[i-1]+wt[i-1];
                       }
                       System.out.println("Process Id  Burst Time  Waiting Time  TurnAround Time \n");
                       float twt=0.0f;
                       float tat=0.0f;
                       
                       for(i=0;i<n;i++){
                       System.out.print(pid[i]+"\t\t" );
                                              System.out.print(bt[i]+"\t\t" );
                                               System.out.print(wt[i]+"\t\t" );
                                               
                                               
                                               
                                                System.out.print((bt[i]+wt[i])+"\t\t" );
                                                 System.out.println();
                                                 twt+=wt[i];
                                                 tat+=(wt[i]+bt[i]);
                                                 }
                                                 float att,awt;
                                                 awt=twt/n;
                                                 att = (tat - n) / n;

                                                 System.out.println("Avg. waiting time : "+awt);
                                                 System.out.println("Avg.turnaround time"+att);
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}

