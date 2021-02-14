
public class Main {
	static final String DEFAULT_HOST = "localhost";
	static final int DEFAULT_PORT = 3331;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//Interface fenetre =new Interface("Java Anh-Vu Nguyen");
		
	    
	    Client client = null;
	    
	    try {
	      client = new Client(DEFAULT_HOST, DEFAULT_PORT);
	    }
	    catch (Exception e) {
	      System.err.println("Client: Couldn't connect to "+DEFAULT_HOST+":"+DEFAULT_PORT);
	      System.exit(1);
	    }
	    
	    System.out.println("Client connected to "+DEFAULT_HOST+":"+DEFAULT_PORT);
	    Interface swing= new Interface("Java Anh-Vu Nguyen", client);
	    
	}

}
