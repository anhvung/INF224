import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.*;
import javax.swing.*;

public class Interface extends JFrame {
	private static final long serialVersionUID = 1L;
	private Client client;
	private static JTextArea textArea;
	
	
	Interface(String title,Client client) {
				
				super(title); // titre de la fenetre
				this.client=client;
				setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//ferme la fentre en clquant sur la croix
				
				textArea = new JTextArea(15, 50);
			
				JScrollPane scrollPane = new JScrollPane(textArea);
				
				
				Find find = new Find("Find");
				Open open = new Open("Open");
				ShowAll showAll = new ShowAll("Show All");
				Exit exit = new Exit("Terminate all");
				
				JButton findBtn = new JButton(find);
				JButton openBtn = new JButton(open);
				JButton showBtn = new JButton(showAll);
				JButton exitBtn = new JButton(exit);
				JToolBar bar = new JToolBar();
				bar.add(findBtn);
				bar.add(openBtn);
				bar.add(showBtn);
				bar.add(exitBtn);
				
				
				//menu
				JMenuBar menuBar = new JMenuBar();
				JMenu menu = new JMenu("Menu");
				menu.add(new JMenuItem(find));
				menu.add(new JMenuItem(open));
				menu.add(new JMenuItem(showAll));
				menu.add(new JMenuItem(exit));
				menuBar.add(menu);
				setJMenuBar(menuBar);
				
				textArea.setBackground(Color.ORANGE); //vlc color
				add(bar, BorderLayout.NORTH);
				add(scrollPane, BorderLayout.SOUTH);
				textArea.append("Les informations doivent aussi etre ecrites dans le textArea \n");
				
				
				pack();
				setVisible(true);
	}
	
	
	/**
	 * FIND MEDIA BY NAME, WRITE IN textArea
	 */
	class Find extends AbstractAction {
		private static final long serialVersionUID = 4;
		public Find(String name) {
			super(name);
		}
		@Override
		public void actionPerformed(ActionEvent e) {
			String request=textArea.getText();
			String send =request.substring(request.lastIndexOf("\n")+1);
			String answer = client.send("0 " + send);
			answer=answer.replace("&&n", "\n");

			textArea.append("\n"+answer+"\n");
		}

	}

	/**
	 * OPEN MEDIA ON SERVER IF EXISTS
	 */

	class Open extends AbstractAction {
		private static final long serialVersionUID = 1;
		public Open(String name) {
			super(name);
		}
		@Override
		public void actionPerformed(ActionEvent e) {
			String request=textArea.getText();
			String send =request.substring(request.lastIndexOf("\n")+1);
			String answer = client.send("1 " + send);
			
			textArea.append("\n"+answer+"\n");
			
		}
	}
	/**
	* SHOW ALL EXISTING MEDIA
	*/

	class ShowAll extends AbstractAction {
		private static final long serialVersionUID = 2;
		public ShowAll(String name) {
			super(name);
		}
		@Override
		public void actionPerformed(ActionEvent e) {
		
			String answer = client.send("2");
			answer=answer.replace("&&n", "\n ============ \n");
			
			textArea.append(answer+"\n");
		}
	}

	/**
	* CLOSE WINDOW AND TCP CONNECTION 
	*/

	class Exit extends AbstractAction {
		private static final long serialVersionUID = 3;
		public Exit(String name) {
			super(name);
		}
		@Override
		public void actionPerformed(ActionEvent e) {
			client.send("3");
			System.exit(0);

		}
	}
	

}
