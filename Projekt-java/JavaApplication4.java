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
public class JavaApplication4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner odczyt = new Scanner(System.in);
        Kino kino;
	boolean condition=true;
	kino= new Kino();
        {
            kino.g_sala(20,18,0);
            kino.g_sala(18,16,1);
            kino.g_film("AUTA 2",120,3,0);
            kino.g_film("Wiedzmin",160,12,1);
            kino.g_seans(17,20,12,05,2014,"2D",0,0,0);
            kino.g_seans(17,20,12,05,2014,"3D",1,0,1);
            kino.g_seans(13,20,12,05,2014,"3D",2,1,0);
            kino.g_ticket(20,25,15,20,14,18);
	}
	do {
		int x;
		System.out.println();
		System.out.println("1. Zarzadzaj salami");
		System.out.println("2. Zarzadzaj filmami");
		System.out.println("3. Zarzadzaj seansami");
		System.out.println("4. Zmien ceny bitetow");
		System.out.println("5. Zarzadzaj rezerwacjami");
		System.out.println("6. Bilety");
		System.out.println("9. WYJSCIE");
		x=odczyt.nextInt();
		System.out.println();
		switch(x)
		{
			case 1:
				{
					boolean menu=true;
					int y;
					do
					{
						System.out.println();
						System.out.println("1. dodaj sale");
						System.out.println("2. usun sale");
						System.out.println("3. zobacz sale");
						System.out.println("0. Powrot");
						System.out.println("9. WYJSCIE");
						y=odczyt.nextInt();
						System.out.println();
						switch(y)
						{
							case 1:
								kino.add_sala();
								break;
							case 2:
								if(kino.check_sala())
								{
									int z;
									System.out.println("wybierz sale do usuniecia");
									kino.view_sala();
									z=odczyt.nextInt();
									z--;
									kino.delete_sala(z);
								}
								else
								{
									System.out.println("Brak Sal");
								}
								break;
							case 3:
								if(kino.check_sala())
									kino.view_sala();
								else
									System.out.println("Brak Sal");
								System.out.println();
								break;
							case 0:
								menu=false;
								break;
							case 9:
								condition=false;
								break;
						}
					}while(menu && condition);
				}
				break;
			case 2:
				{
					boolean menu=true;
					int y;
					do
					{
						System.out.println();
						System.out.println("1. dodaj film");
						System.out.println("2. usun film");
						System.out.println("3. zobacz filmy");
						System.out.println("0. Powrot");
						System.out.println("9. WYJSCIE");
						y=odczyt.nextInt();
						System.out.println();
						switch(y)
						{
							case 1:
								kino.add_film();
								break;
							case 2:
								if(kino.check_film())
								{
									int z;
									System.out.println("wybierz film do usuniecia");
									kino.view_film();
									z=odczyt.nextInt();
									z--;
									kino.delete_film(z);
								}
								else
								{
									System.out.println("Brak Filmow");
									System.out.println();
								}
								break;
							case 3:
								if(kino.check_film())
									kino.view_film();
								else
									System.out.println("Brak filmow");
								System.out.println();
                                                                System.out.println();
								break;
							case 0:
								menu=false;
								break;
							case 9:
								condition=false;
								break;
						}
					}while(menu && condition);
				}
				break;
			case 3:
				{
					boolean menu=true;
					int y;
					do
					{
						System.out.println();
						System.out.println("1. dodaj seans");
						System.out.println("2. usun seans");
						System.out.println("3. zobacz seansy");
						System.out.println("4. zobacz rozklad miejsc na sali");
						System.out.println("0. Powrot");
						System.out.println("9. WYJSCIE");
						y=odczyt.nextInt();
						System.out.println();
						switch(y)
						{
							case 1:
								kino.add_seans();
								break;
							case 2:
								if(kino.check_seans())
								{
									int z;
									System.out.println("wybierz seans do usuniecia");
									kino.view_seans();
									z=odczyt.nextInt();
									z--;
									kino.delete_seans(z);
								}
								else
								{
									System.out.println("Brak Seansow");
									System.out.println();
								}
								break;
							case 3:
								if(kino.check_seans())
									kino.view_seans();
								else
									System.out.println("Brak Seansow");
								System.out.println();
								break;
							case 4:
								if(kino.check_seans())
								{
									int zx;
									System.out.println("wybierz seans");
									kino.view_seans();
									zx=odczyt.nextInt();
									zx--;
									kino.view_seans_sala(zx);
								}
								else
									System.out.println("Brak Seansow");
								System.out.println();
								break;
							case 0:
								menu=false;
								break;
							case 9:
								condition=false;
								break;
						}
					}while(menu && condition);
				}
				break;
			case 4:
				kino.set_tickets();
				break;
			case 5:
				{	
					boolean menu=true;
					int y;
					do
					{
						System.out.println();
						System.out.println("1. dodaj rezerwacje");
						System.out.println("2. usun rezerwacje");
						System.out.println("3. zobacz rezerwacje");
						System.out.println("0. Powrot");
						System.out.println("9. WYJSCIE");
						y=odczyt.nextInt();
						System.out.println();
						switch(y)
						{
							case 1:
								kino.add_reservation();
								break;
							case 2:
								if(kino.check_reservation())
								{
									int z;
									System.out.println("wybierz rezerwacje do usuniecia");
									kino.view_reservation();
									z=odczyt.nextInt();
									z--;
									kino.delete_reservation(z);
								}
								else
								{
									System.out.println("Brak Rezerwacji");
									System.out.println();
								}
								break;
							case 3:
								if(kino.check_reservation())
									kino.view_reservation();
								else
									System.out.println("Brak Rezerwacji");
								System.out.println();
								break;
							case 0:
								menu=false;
								break;
							case 9:
								condition=false;
								break;
						}
					}while(menu && condition);
				}
				break;
			case 6:
				{
					boolean menu=true;
					int y,z;
					do
					{
						System.out.println();
						System.out.println("1. Ceny biletow");
						System.out.println("2. Kup Bilet");
						System.out.println("0. Powrot");
						System.out.println("9. WYJSCIE");
						z=odczyt.nextInt();
						System.out.println();
						switch(z)
						{
							case 1:
								kino.view_ticket_price();
								System.out.println();
								break;
							case 2:
								System.out.println("Ile bitetow chcesz kupic?");
								y=odczyt.nextInt();
								kino.buy_ticket(y);
								break;
							case 0:
								menu=false;;
								break;
							case 9:
								condition=false;
								break;
							default:
								break;
						}
					}while(menu && condition);
				}
				break;
			case 9:
				condition=false;
				break;
		}
	}while(condition);
	kino=null;
        odczyt=null;
    }
    
}
