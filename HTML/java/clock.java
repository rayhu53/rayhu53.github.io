/**
  Demo_4
  ¹q¸£®ÉÄÁ
*/

import java.applet.*;
import java.awt.*;
import java.util.Date;

public class clock extends Applet implements Runnable
{
	Font font;
	Date show_date;
	Thread the_thread;
	public void init()
	{
		font = new Font("Arial",Font.BOLD,36);
	}
	public void start()
	{
		if(the_thread == null)
		{
			the_thread=new Thread(this);
			the_thread.start();
		}
	}
	public void stop()
	{
		if(the_thread!=null)
		{
			the_thread.stop();
			the_thread=null;
		}
	}
	public void run()
	{
		while(true)
		{
			show_date=new Date();
			repaint();
			try{ Thread.sleep(1000); }
			catch(Exception e){}
		}
	}
	public void paint(Graphics pen)
	{
		pen.setFont(font);
		pen.setColor(Color.red);
		pen.drawString(show_date.toString(),50,50);
	}
}
		
