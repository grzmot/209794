/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Maciej
 */
import java.util.Scanner;
public class Kino {
    private Sala[] sala;
    private Film[] film;
    private Seans[] seans;
    private Reservation[] reservation;
    private Ticket ticket;
    private int size_sala;
    private int size_film;
    private int size_seans;
    private int size_reservation;
	
    private void resize_sala(){
        Sala[] tmp;
	tmp= new Sala [size_sala];
	for(int i=0;i<size_sala;i++)
		tmp[i]=new Sala(sala[i]);
	for(int i=0;i<size_sala;i++)
		sala[i]=null;
	sala=null;
	size_sala*=2;
	sala= new Sala [size_sala];
	for(int i=0;i<size_sala/2;i++)
		sala[i]=new Sala(tmp[i]);
	for(int i=0;i<size_sala/2;i++)
			tmp[i]=null;
	tmp=null;
	for(int i=size_sala/2;i<size_sala;i++)
		sala[i]=null;
    }
    private void resize_film(){
        Film[] tmp;
	tmp= new Film [size_film];
	for(int i=0;i<size_film;i++)
		tmp[i]=new Film(film[i]);
	for(int i=0;i<size_film;i++)
		film[i]=null;
	film=null;
	size_film*=2;
	film= new Film [size_film];
	for(int i=0;i<size_film/2;i++)
		film[i]=new Film(tmp[i]);
	for(int i=0;i<size_film/2;i++)
			tmp[i]=null;
	tmp=null;
	for(int i=size_film/2;i<size_film;i++)
		film[i]=null;
    }
    private void resize_seans(){
        Seans[] tmp;
	tmp= new Seans [size_seans];
	for(int i=0;i<size_seans;i++)
		tmp[i]=new Seans(seans[i]);
	for(int i=0;i<size_seans;i++)
		seans[i]=null;
	seans=null;
	size_seans*=2;
	seans= new Seans [size_seans];
	for(int i=0;i<size_seans/2;i++)
		seans[i]=new Seans(tmp[i]);
	for(int i=0;i<size_seans/2;i++)
			tmp[i]=null;
	tmp=null;
	for(int i=size_seans/2;i<size_seans;i++)
		seans[i]=null;
    }
    private void resize_reservation(){
        Reservation[] tmp;
	tmp= new Reservation [size_reservation];
	for(int i=0;i<size_reservation;i++)
		tmp[i]=new Reservation(reservation[i]);
	for(int i=0;i<size_reservation;i++)
		reservation[i]=null;
	reservation=null;
	size_reservation*=2;
	reservation= new Reservation [size_reservation];
	for(int i=0;i<size_reservation/2;i++)
		reservation[i]=new Reservation(tmp[i]);
	for(int i=0;i<size_reservation/2;i++)
			tmp[i]=null;
	tmp=null;
	for(int i=size_reservation/2;i<size_reservation;i++)
		reservation[i]=null;
    }
	
    private boolean check_relations_sala(int id_sala){
        int x=0;
	for(int i=0;i<size_seans;i++)
        {
		if(seans[i]!=null)
                
			if(seans[i].get_sala().get_number()==id_sala)
			{
                            Scanner odczyt = new Scanner(System.in);
				do
				{
                                    System.out.println("Usuniecie sali spowoduje usuniecie powiazanych z na seansow");
                                    System.out.println("1. Kontynuuj");
                                    System.out.println("2. Anuluj");
					x=odczyt.nextInt();
				}while(x!=1 && x!=2);
                                odczyt=null;
				if (x==1)
				{
					x=0;
					for(int j=0;j<size_seans;j++)
						if(seans[j]!=null)
							if(seans[j].get_sala().get_number()==id_sala)
								if (check_relations_seans(j,x))
									{
										x=1;
										delete_seans2(j);
									}
									else
										return false;
					return true;
				}
				else
					return false;
			}
                    
        }
		return true;
    }
    private boolean check_relations_film(int id_film){
        int x=0;
	for(int i=0;i<size_seans;i++)
        {
		if(seans[i]!=null)
			if(seans[i].get_id_film()==id_film)
			{
                            Scanner odczyt = new Scanner(System.in);
				do
				{
					System.out.println("Usuniecie sali spowoduje usuniecie powiazanych z na seansow");
					System.out.println("1. Kontynuuj");
                                        System.out.println("2. Anuluj");
					x=odczyt.nextInt();
				}while(x!=1 && x!=2);
                                odczyt=null;
				if (x==1)
				{
					x=0;
					for(int j=0;j<size_seans;j++)
						if(seans[j]!=null)
							if(seans[j].get_id_film()==id_film)
								if (check_relations_seans(j,x))
									{
										x=1;
										delete_seans2(j);
									}
									else
										return false;
					return true;
				}
				else
					return false;
			}
        }
		return true;
    }
    private boolean check_relations_seans(int id_seans, int x){
        for(int i=0;i<size_reservation;i++)
		if(reservation[i]!=null)
                {
			if(reservation[i].get_seans_id()==id_seans)
			{
                            Scanner odczyt = new Scanner(System.in);
				while(x!=1 && x!=2)
				{
                                    System.out.println("Usuniecie seansu spowoduje usuniecie powiazanych z nim rezerwacji");
                                    System.out.println("1. Kontynuuj");
                                    System.out.println("2. Anuluj");
                                    x=odczyt.nextInt();
				}
                                odczyt=null;
				if (x==1)
				{
					for(int j=0;j<size_reservation;j++)
						if(reservation[j]!=null)
							if(reservation[j].get_seans_id()==id_seans)
								delete_reservation(j);
					return true;
				}
				else
					return false;
			}
			else
				return true;
                }
	return true;
    }
	
    private boolean check_film(int id){
        return (film[id]==null);
    }
    private boolean check_sala(int id){
        return (sala[id]==null);
    }
    private boolean check_seans(int id){
        return (seans[id]==null);
    }
    
    public Kino(){
        size_sala=6;
	size_film=10;
	size_seans=20;
	size_reservation=10;
	sala=new Sala [size_sala];
	for(int i=0;i<size_sala;i++)
		sala[i]=null;
	film=new Film [size_film];
	for(int i=0;i<size_film;i++)
		film[i]=null;
	seans=new Seans [size_seans];
	for(int i=0;i<size_seans;i++)
		seans[i]=null;
	reservation=new Reservation [size_reservation];
	for(int i=0;i<size_reservation;i++)
		reservation[i]=null;
	ticket=null;
    }
    @Override
    protected void finalize(){
        if(ticket!=null)
		ticket=null;
	for(int i=0;i<size_sala;i++)
		if(sala[i]!=null)
			sala[i]=null;
	sala=null;
	for(int i=0;i<size_film;i++)
		if(film[i]!=null)
			film[i]=null;
	film=null;
	for(int i=0;i<size_seans;i++)
		if(seans[i]!=null)
			seans[i]=null;
	seans=null;
	for(int i=0;i<size_reservation;i++)
		if(reservation[i]!=null)
			reservation[i]=null;
	reservation=null;
    }
    
    public Seans get_seans(int id_seans){
        return seans[id_seans];
    }
    
    public void view_sala(){
        for (int j=0;j<size_sala;j++)
		if(sala[j]!=null)
			System.out.println("Sala nr.: "+(j+1)+"  ikosc miejsc: "+sala[j].get_number_of_seats());
    }
    public void view_sala(int id_sala){
        sala[id_sala].view_spaces();
    }
    public void view_film(){
        for (int j=0;j<size_film;j++)
		if(film[j]!=null)
                {
                    System.out.print((j+1)+". ");
                    film[j].view_film();
                    System.out.println();
                }
    }
    public void view_film(int id_film){
        film[id_film].view_film();
        System.out.println();
    }
    public void view_seans(){
        for (int j=0;j<size_seans;j++)
		if(seans[j]!=null)
                {
                    System.out.print(j+1+". ");
                    seans[j].view_seans();
                    System.out.println();     
                }
    }
    public void view_seans(int id_seans){
        seans[id_seans].view_seans();
    }
    public void view_seans_sala(int id_seans){
        seans[id_seans].get_sala().view_spaces();
    }
    public void view_reservation(){
        for (int j=0;j<size_reservation;j++)
		if(reservation[j]!=null)
		{
                    System.out.print(j+1+". Film: "+seans[reservation[j].get_seans_id()].get_title());
                    System.out.print(" godz: "+seans[reservation[j].get_seans_id()].get_hour().get_hour_g()+":"+seans[reservation[j].get_seans_id()].get_hour().get_hour_m());
                    System.out.print(" sala: "+(seans[reservation[j].get_seans_id()].get_sala().get_number())+1);
			for(int i=0;i<(reservation[j].get_number());i++)
                            System.out.print(" Miejsce "+i+1+": "+((reservation[j].get_row(i))+1)+"/"+((reservation[j].get_space(i))+1)+" ");
			System.out.println();
		}
    }
    public void set_tickets(){
        Scanner odczyt = new Scanner(System.in);
        if(ticket==null)
	{
		ticket= new Ticket();
                System.out.print("Podaj cene biletu Normalnego-2D");
                System.out.print("Podaj cene biletu Normalnego-3D");
                System.out.print("Podaj cene biletu Ulgowego-2D");
                System.out.print("Podaj cene biletu Ulgowego-3D");
                System.out.print("Podaj cene biletu Grupowego-2D");
                System.out.print("Podaj cene biletu Grupowego-3D");
	}
	else
	{
		int i=0;
		ticket.view_price_ticket();
		System.out.println("ile cen biletow chcesz znienic?(max 6)");
		i=odczyt.nextInt();
		if(i>6)
			i=6;
		for(int j=0;j<i;j++)
		{
			System.out.println("ktora cene biletu chcesz zmienic?");
			System.out.println("1 -Normalny 2D");
			System.out.println("2 -Normalny 3D");
			System.out.println("3 -Ulgowy 2D");
			System.out.println("4 -Ulgowy 3D");
			System.out.println("5 -Grupowy 2D");
			System.out.println("6 -Grupowy 3D");
			int x;
			double y;
			x=odczyt.nextInt();
			System.out.println("podaj nowa cene: ");
			y=odczyt.nextDouble();
			switch(x)
			{
				case 1: 
					ticket.set_normal_2D(y);
					break;
				case 2: 
					ticket.set_normal_3D(y);
					break;
				case 3: 
					ticket.set_reduced_2D(y);
					break;
				case 4: 
					ticket.set_reduced_3D(y);
					break;
				case 5: 
					ticket.set_group_2D(y);
					break;
				case 6: 
					ticket.set_group_3D(y);
					break;
			}
		}
	}
        odczyt=null;
    }
    public void view_ticket_price(){
        if(ticket!=null)
            ticket.view_price_ticket();
    }
    public void buy_ticket(int number){
        Scanner odczyt = new Scanner(System.in);
        boolean confirmation;
	int[] tickets;
        int q;
	tickets= new int [number];
	int x;
        int[][] space=new int[2][number];
	do
	{
		System.out.println("wybierz seans");
		view_seans();
		x=odczyt.nextInt();
		x--;
	} while(this.check_seans(x));
	if(number==1)
		System.out.println("wybierz miejsce");
	else 
		System.out.println("wybierz miejsca");
	seans[x].get_sala().view_spaces();
	if (number==1)
	{
		do
		{
			System.out.print("Rząd: ");
			space[0][0]=odczyt.nextInt();
                        space[0][0]--;
                        System.out.println();
                        System.out.print("Miejsce: ");
                        space[1][0]=odczyt.nextInt();
                        space[1][0]--;
			if (!(seans[x].get_sala().place_free(space[0][0],space[1][0])))
				System.out.println("miejsce zajete");
		}while (!(seans[x].get_sala().place_free(space[0][0],space[1][0])));
		do
		{
			System.out.println("wybiez bilet");
			System.out.println("1. Normalny ");
                        System.out.println("2. Ulgowy");
			tickets[0]=odczyt.nextInt();
		}while(!(tickets[0]>0 && tickets[0]<3));
                System.out.println();
                System.out.println();
		System.out.println(seans[x].get_title());
		System.out.println("godzina: "+seans[x].get_hour().get_hour_g()+":"+seans[x].get_hour().get_hour_m());
		System.out.print("RZAD: "+space[0][0]);
                System.out.println(" / MIEJSCE: "+space[1][0]);
		if ((seans[x].get_type_seans()=="2D")&& tickets[0]==1)
                {
			System.out.println("Film 2D");
                        System.out.println("Cena: "+ticket.get_normal_2D()+"zl");
                }
		else if((seans[x].get_type_seans()=="3D")&& tickets[0]==1)
                {
                        System.out.println("Film 3D");
                        System.out.println("Cena: "+ticket.get_normal_3D()+"zl");
                }
		else if((seans[x].get_type_seans()=="2D")&& tickets[0]==2)
                {
                        System.out.println("Film 2D");
                        System.out.println("Cena: "+ticket.get_reduced_2D()+"zl");
                }
		else
                {
                        System.out.println("Film 3D");
                        System.out.println("Cena: "+ticket.get_reduced_3D()+"zl");
                }
		System.out.println("potwierdz zakup");
                System.out.println("1-POTWIERDZ");
                System.out.println("2-ANULUJ");
		q=odczyt.nextInt();
		if(q==1)
			confirmation=true;
		else
			confirmation=false;
	}
	else
	{
		for (int i=0; i<number;i++)
		{
			do
			{
				System.out.println("miejsce "+(i+1));
				System.out.print("Rząd: ");
                                space[0][i]=odczyt.nextInt();
                                space[0][i]--;
                                System.out.println();
                                System.out.print("Miejsce: ");
                                space[1][i]=odczyt.nextInt();
                                space[1][i]--;
				if (!(seans[x].get_sala().place_free(space[0][i-1],space[1][i-1])))
					System.out.println("miejsce zajete");
			}while (!(seans[x].get_sala().place_free(space[0][i-1],space[1][i-1])));
		}
		System.out.println("wybiez bilet");
		System.out.println("wybiez bilet");
		System.out.println("1. Normalny ");
                System.out.println("2. Ulgowy");
		for (int i=0;i<number;i++)
		{
			
			System.out.print("bilet "+(i+1)+": ");
			tickets[i]=odczyt.nextInt();
		}
		double price=0;
		for (int i=0;i<number;i++)
		{
			System.out.print("bilet "+(i+1));
                        System.out.println();
                        System.out.println();
			System.out.println(seans[x].get_title());
			System.out.println("godzina: "+seans[x].get_hour().get_hour_g()+":"+seans[x].get_hour().get_hour_m());
			System.out.println("RZAD: "+space[0][i]+" / MIEJSCE: "+space[1][i]);
			if ((seans[x].get_type_seans()=="2D")&& tickets[i]==1)
			{
				System.out.println("Film 2D");
                                System.out.println("Cena: "+ticket.get_normal_2D()+"zl");
				price+=ticket.get_normal_2D();
			}
			else if((seans[x].get_type_seans()=="3D")&& tickets[i]==1)
			{
				System.out.println("Film 3D");
                                System.out.println("Cena: "+ticket.get_normal_3D()+"zl");
				price+=ticket.get_normal_3D();
			}
			else if((seans[x].get_type_seans()=="2D")&& tickets[i]==2)
			{
				System.out.println("Film 2D");
                                System.out.println("Cena: "+ticket.get_reduced_2D()+"zl");
				price+=ticket.get_reduced_2D();
			}
			else
			{
				System.out.println("Film 3D");
                                System.out.println("Cena: "+ticket.get_reduced_3D()+"zl");
				price+=ticket.get_reduced_3D();
			}
		}
		System.out.println("potwierdz zakup");
                System.out.println("1-POTWIERDZ");
                System.out.println("2-ANULUJ");
		q=odczyt.nextInt();
		if(q==1)
			confirmation=true;
		else
			confirmation=false;
	}
	if(confirmation)
			seans[x].get_sala().take_seat(space[0],space[1],number);
	space= null;
	tickets=null;
    }

    public void g_ticket(double normal_2D, double normal_3D, double reduced_2D, double reduced_3D, double group_2D,double group_3D){
        if (ticket==null)
		ticket= new Ticket(normal_2D,normal_3D,reduced_2D,reduced_3D,group_2D,group_3D);
    }
    public void g_sala(int row,int space,int id){
        if(sala[id]==null)
	{
		sala[id]=new Sala(row,space,id);
		sala[id].plus_number_of_hall();
	}
    }
    public void g_film(String title,int time,int restrictions, int id){
        if(film[id]==null)
	{
		film[id]=new Film(title,time,restrictions,id);
		film[id].plus_number_of_film();
	}
    }
    public void g_seans(int g,int m,int dd,int dm,int dy, String type_seans,int id,int id_film,int id_sala){
    if(seans[id]==null)
	{
		seans[id]=new Seans(film[id_film],g,m,dd,dm,dy,sala[id_sala],type_seans);
		//seans[id]->plus_number_of_seans();
	}
}
	
	
    public void add_sala(){
        Scanner odczyt = new Scanner(System.in);
        int i=0;
	i--;
	boolean x=true;
	do
	{
		i++;
		if(sala[i]==null)
			x=false;
	}while((i<size_sala)&& x);
	if(x)
		resize_sala();
	int row,space;
        System.out.println();
	System.out.print("podaj ilosc rzedow: ");
	row=odczyt.nextInt();
        System.out.println();
	System.out.print("podaj ilosc miejsc w rzedzie: ");
	space=odczyt.nextInt();
	sala[i]=new Sala();
	sala[i].plus_number_of_hall();
	sala[i].set_spaces(row,space);
	sala[i].set_number(i);
        odczyt=null;
    }
    public void add_film(){
        int i=0;
	i--;
	boolean x=true;
	do
	{
		i++;
		if(film[i]==null)
			x=false;
	}while((i<size_film)&& x);
	if(x)
		resize_film();
	film[i]=new Film();
	film[i].read_film();
	film[i].set_id_film(i);
    }
    public void add_seans(){
        Scanner odczyt = new Scanner(System.in);
        if((sala[0].get_number_of_hall()<1)&&( film[0].get_number_of_film()<1))
	{
		System.out.println("Brak sal lub/i fimow");
                System.out.println();
	}
	else
	{
		
		System.out.println(sala[0].get_number_of_hall());
		int i=0,s,f;//s- number od sala, f- number of film
		String t="";//t-type of film 2D/3D
		i--;
		boolean x=true;
		do
		{
			i++;
			if(seans[i]==null)
				x=false;
		}while((i<size_seans)&& x);
		if(x)
			resize_seans();
		int dd,dm,dy;
		System.out.println("data:");
		do
		{
			System.out.print("Dzien: ");
			dd=odczyt.nextInt();
		} while(!(dd>0 && dd<32));
		do
		{
			System.out.print("Miesiac: ");
			dm=odczyt.nextInt();
		} while(!(dm>0 && dm<13));
		do
		{
			System.out.print("Rok: ");
			dy=odczyt.nextInt();
		} while(dy<2014);
		view_film();
		do 
		{
			System.out.println("wybierz film:");
			f=odczyt.nextInt();
			f--;
		}while(this.check_film(f));
		for (int j=0;j<size_sala;j++)
			if(sala[j]!=null)
                        {
                            System.out.print("Sala nr: "+(j+1));
                            System.out.println(" ilosc miejsc: "+sala[j].get_number_of_seats());
                        }
		do
		{
                        System.out.println();
			System.out.println("wybierz Sale:");
			s=odczyt.nextInt();
			s--;
		} while (this.check_sala(s));
		System.out.print("podaj godzine seansu: ");
		int g=0,m=0;
                System.out.print("Godzina: ");
                g=odczyt.nextInt();
                System.out.print("Minut: ");
                m=odczyt.nextInt();
		System.out.print("podaj typ filmu(2D/3D): ");
                String psr=odczyt.nextLine();
                t="x";
                t=odczyt.nextLine();
                System.out.print("");
		seans[i]=new Seans(film[f],g,m,dd,dm,dy,sala[s],t);
		//seans[i]->plus_number_of_seans();
	}
        odczyt=null;
    }
    public void add_reservation(){
        Scanner odczyt = new Scanner(System.in);
        if ((seans[0].get_number_of_seans())<1)
	{
		System.out.println("Brak seansow");
                System.out.println();
	}
	else
	{
		int i=0;
		int n;
                int [] row,space,xy,y;
                xy=new int[1];
                y=new int[1];
		int id_seans;
		i--;
		boolean x=true;
		do
		{
			i++;
			if(reservation[i]==null)
				x=false;
		}while((i<size_reservation)&& x);
		if(x)
			resize_reservation();
		System.out.println("wybierz seans");
		view_seans();
		id_seans=odczyt.nextInt();
		id_seans--;
		System.out.println("ile miejsc chcesz zarezerwowac?");
		n=odczyt.nextInt();
		row=new int[n];
		space=new int[n];
		System.out.println("wybierz miejsce: ");
				seans[id_seans].get_sala().view_spaces();
		for(int j=0;j<n;j++)
		{
			do
			{
				System.out.println("Miejsce "+j+1);
                                System.out.print("Rzad: ");
				row[j]=odczyt.nextInt();
                                System.out.println();
                                System.out.print("Miejsce: ");
                                space[j]=odczyt.nextInt();
                                System.out.println();
				row[j]--;
				space[j]--;
				if(!(seans[id_seans].get_sala().place_free(row[j],space[j])))
					System.out.println("miejsce zajete");
			} while(!(seans[id_seans].get_sala().place_free(row[j],space[j])));
			xy[0]=row[j];
			y[0]=space[j];
			seans[id_seans].get_sala().take_seat(xy,y,1);
		}
		reservation[i]=new Reservation(id_seans,i,n,row,space);
		reservation[i].plus_number_of_reservation();
		//reservation[i]->plus_number_of_reservation();
		xy=null;
                y=null;
                row=null;
		space=null;
	}
        odczyt=null;
    }
    
	//id_xx- is a number in the array
    public void delete_sala(int id_sala){
        sala[id_sala].minus_number_of_hall();
	if(sala[id_sala]!=null)
		if(check_relations_sala(id_sala))
		{
			sala[id_sala]=null;
		}
	else 
		sala[id_sala]=null;
}
    public void delete_film(int id_film)
    {
        film[id_film].minus_number_of_film();
	if(film[id_film]!=null)
		if(check_relations_film(id_film))
		{
			film[id_film]=null;
		}
	else
		film[id_film]=null;
    }
    public void delete_seans(int id_seans){
        if(seans[id_seans]!=null)
	{
		if(check_relations_seans(id_seans,0))
		{
			seans[id_seans]=null;
		}
	}
	else
		seans[id_seans]=null;
    }
    public void delete_seans2(int id_seans){
        if(seans[id_seans]!=null)
	seans[id_seans]=null;
    }
    public void delete_reservation(int id_reservation){
        if(reservation[id_reservation]!=null)
		{
			seans[reservation[id_reservation].get_seans_id()].get_sala().relase_seat(reservation[id_reservation].get_row(),reservation[id_reservation].get_space(),reservation[id_reservation].get_number());
			reservation[id_reservation].minus_number_of_reservation();
			reservation[id_reservation]=null;
		}
	reservation[id_reservation]=null;
    }
    public boolean check_sala(){
        return sala[0].get_number_of_hall()>0;
    }
    public boolean check_film(){
        return (film[0].get_number_of_film()>0);
    }
    public boolean check_seans(){
        return seans[0].get_number_of_seans()>0;
    }
    public boolean check_reservation(){
        return reservation[0].get_number_of_reservation()>0;
    }
}