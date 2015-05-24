// CSE42102 [OOP Assign7 20141435] Song-ei Lee
import java.io.*;

// counts the longest time for nap using his scheduler.
public class Nap {
	public static void main(String[] args) throws IOException {
		FileReader testFile = new FileReader("test.txt");
		BufferedReader bufIn = new BufferedReader(testFile);

		String str;
		int dayCount=0;

		while(true) {
			str = bufIn.readLine();
			if(str == null) break; // end of file
			if(str.length()==1) {
				dayCount += 1;

				int numOfCase = Integer.parseInt(str);
				int start_time=0, end_time=0;
				int diff = 0;
				int for_time=0;
				String at_time="";

				for(int i=0; i<numOfCase; i++) {
					str = bufIn.readLine();

					// divides the input string into start time part and end time part.
					// then divides each part again into hours part and minutes part.
					String[] parts = str.split(" ");
					String[] start = parts[0].split(":");
					String[] end = parts[1].split(":");

					// start_time : make the time unit minutes
					// diff : difference between time of start next schedule and time of end previous schedule.
					// end_time : make the time unit minutes
					start_time = (Integer.parseInt(start[0])-10)*60+Integer.parseInt(start[1]);
					diff = start_time-end_time;
					if(for_time<diff) {for_time=diff; at_time=(String.valueOf(10+(end_time/60))+":"+String.format("%02d",end_time%60));}
					end_time = (Integer.parseInt(end[0])-10)*60+Integer.parseInt(end[1]);

					// for the case of from the end of schedule to last time (18:00)
					if(i==numOfCase-1) {
						diff = 480-end_time;
						if(for_time<diff) {for_time=diff; at_time=(String.valueOf(10+(end_time/60))+":"+String.format("%02d",end_time%60));}
					}
				}
				// prints the result (with hours or not)
				System.out.print("Day #"+dayCount+": the longest nap starts at "+at_time+" and will last for ");
				if(for_time/60>0) System.out.println(String.valueOf(for_time/60)+" hours "+String.valueOf(for_time%60)+" minutes.");
				else System.out.println(String.valueOf(for_time)+" minutes.");
			}
		}
	}
}
