import java.io.*;
import java.util.*;

class fileReader {
	private Scanner iFile;

	// Opens file
	void openFile(int i){
		Integer year = 2006 + i;
		String filename = "babynameranking" + year + ".txt";
		
		try {
			 iFile = new Scanner(new BufferedReader(new FileReader (filename) ));
		}
		catch (Exception e){
			System.out.println("Error! Could not find file. " + e);
		}		
	}

	// Reads file
	void readFile(ArrayList<Map<String, Integer>> boys, ArrayList<Map<String, Integer>> girls){
		// Create the HashMaps
		HashMap<String, Integer> boyRanking = new HashMap<>();
		HashMap<String, Integer> girlRanking = new HashMap<>();

		// Add 1000 elements to the HashMaps
		while (iFile.hasNext() ){
			Integer num = iFile.nextInt();
			String boyName = iFile.next();
			String girlName = iFile.next();

			boyRanking.put(boyName, num );
			girlRanking.put(girlName, num );
		}

		// Add the HashMaps to the ArrayList
		boys.add(boyRanking);
		girls.add(girlRanking);
	}

	// Closes file
	void closeFile(){
		iFile.close();
	}
}