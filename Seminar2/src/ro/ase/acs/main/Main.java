package ro.ase.acs.main;

import java.io.IOException;

import ro.ase.acs.readers.Reader;
import ro.ase.acs.writers.ConsoleWriter;
import ro.ase.acs.writers.FileWriter;

public class Main {
	
	

	public static void main(String[] args) {
		Orchestrator orchestrator = new Orchestrator(new Reader(), new ConsoleWriter());
		orchestrator.execute();
		
		
	}

}
