import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.event.*;
import java.awt.Dimension;

public class Interface extends JFrame {
	private static final long serialVersionUID = 1L;
	private Client client;
	private static JTextArea textArea;
	
	
	Interface(String title,Client client) {
				
				super(title); // titre de la fenetre
				this.client=client;
				setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//ferme la fentre en clquant sur la croix
				
				textArea = new JTextArea(15, 25);
			
				JScrollPane scrollPane = new JScrollPane(textArea);
				
				
				SearchAction searchAction = new SearchAction("Search");
				PlayAction playAction = new PlayAction("Play");
				ListAction listAction = new ListAction("ListAll");
				CloseAction closeAction = new CloseAction("Close");
				
				JButton searchBtn = new JButton(searchAction);
				JButton playBtn = new JButton(playAction);
				JButton listBtn = new JButton(listAction);
				JButton exitBtn = new JButton(closeAction);
			
				JPanel panelBtn = new JPanel();
				panelBtn.add(playBtn);
				panelBtn.add(listBtn);
				panelBtn.add(exitBtn);
				
				JMenuBar menuBar = new JMenuBar();
				JMenu menu = new JMenu("Menu");
				menu.add(new JMenuItem(searchAction));
				menu.add(new JMenuItem(playAction));
				menu.add(new JMenuItem(listAction));
				menu.add(new JMenuItem(closeAction));
				
				JToolBar bar = new JToolBar();
				bar.add(searchBtn);
				bar.add(playBtn);
				bar.add(listBtn);
				bar.add(exitBtn);
				

				menuBar.add(menu);

				setJMenuBar(menuBar);
				add(bar, BorderLayout.NORTH);
				add(scrollPane, BorderLayout.SOUTH);
				
				
				
				
				pack();
				setVisible(true);
	}
	
	
	/**
	 * Calls client to send a SEARCH request to the server and shows the result in textArea
	 */
	class SearchAction extends AbstractAction {
		private static final long serialVersionUID = 4;
		public SearchAction(String name) {
			super(name);
		}
		@Override
		public void actionPerformed(ActionEvent e) {
			String allText=textArea.getText();
			String command =allText.substring(allText.lastIndexOf("\n")+1);
			String response = client.send("SEARCH " + command);
			response = parseResult(response);
			textArea.append(response);
		}

	}

	/**
	 * Calls client to send a PLAY request to the server and shows the result in textArea
	 */

	class PlayAction extends AbstractAction {
		private static final long serialVersionUID = 1;
		public PlayAction(String name) {
			super(name);
		}
		@Override
		public void actionPerformed(ActionEvent e) {
			String allText=textArea.getText();
			String command =allText.substring(allText.lastIndexOf("\n")+1);
			String response = client.send("PLAY " + command);
			response = parseResult(response);
			textArea.append(response);
			
		}
	}
	/**
	* Calls client to send a LIST request to the server and shows the result in textArea
	*/

	class ListAction extends AbstractAction {
		private static final long serialVersionUID = 2;
		public ListAction(String name) {
			super(name);
		}
		@Override
		public void actionPerformed(ActionEvent e) {
			System.out.println("gg");
			String response = client.send("LIST");
			System.out.println("wtwji");
			response = parseResult(response);
			textArea.append(response);
		}
	}

	/**
	* Close Java execution
	*/

	class CloseAction extends AbstractAction {
		private static final long serialVersionUID = 3;
		public CloseAction(String name) {
			super(name);
		}
		@Override
		public void actionPerformed(ActionEvent e) {
			client.send("QUIT");
			System.exit(0);

		}
	}
	String parseResult(String result) {
		String response = result.replace("||", "\n");
		return response;
	}

}
