
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Maciej
 */
public class Film {
    private String title;
    private int time;
    private int restrictions;
    private int id_film;
    private static int number_of_film=0;
    
    public Film() {
        title="";
	time=0;
	restrictions=0;
	id_film=0;
    }
    public Film(String title,int time,int restrictions, int id_film) {
        this.title=title;
        this.time=time;
        this.restrictions=restrictions;
        this.id_film=id_film;
    }
    public Film(Film film) {
        title=film.title;
	time=film.time;
	restrictions=film.restrictions;
	id_film=film.id_film;
    }
    @Override
    protected void finalize() {
    }
    
    public static int get_number_of_film() {
        return number_of_film;
    }
    public static void plus_number_of_film() {
        number_of_film++;
    }
    public static void minus_number_of_film() {
        number_of_film--;
    }

    public void set_title(String title) {
        this.title=title;
    }
    public void set_time(int time) {
        this.time=time;
    }
    public void set_restrictions(int restrictions)  {
        this.restrictions=restrictions;
    }
    public void set_id_film(int id_film) {
        this.id_film=id_film;
    }

    public String get_title() {
        return title;
    }
    public int get_time() {
        return time;
    }
    public int get_restrictions() {
        return this.restrictions;
    }
    public int get_id_film() {
        return this.id_film;
    }
    public void view_film() {
        System.out.print(this.title+" "+this.time+" +"+this.restrictions);
    }
    public void read_film(){
        Scanner odczyt = new Scanner(System.in);
        System.out.println();
        System.out.print("Tytuł filmu: ");
        this.title=odczyt.nextLine();
        System.out.println();
        System.out.print("długość filmu: ");
        this.time=odczyt.nextInt();
        System.out.println();
        System.out.print("Ograniczenia wiekowe: ");
        this.restrictions=odczyt.nextInt();
        number_of_film++;
    }
}
