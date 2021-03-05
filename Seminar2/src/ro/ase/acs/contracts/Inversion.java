package ro.ase.acs.contracts;

public class Inversion implements Readable, Writeable {
	private Readable reader;
	private Writeable writer;
	
	//IoC
	public void Inversion(Readable reader, Writeable writer) {
		this.reader = reader;
		this.writer = writer;
		
	}

	@Override
	public void print(String message) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public String read() {
		// TODO Auto-generated method stub
		return null;
	}
	

	
	
	
	
}
