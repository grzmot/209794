/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Maciej
 */
public class Seans extends Film {
    private Day day;
    private Hour hour;
    private Sala sala;
    private String type_seans;
    private static int number_of_seans=0;
    
    public Seans() {
        //day= new day()
        day=new Day(0,0,0);
        hour = new Hour(0,0);
        sala=null;
        type_seans="";
        number_of_seans++;
    }
    public Seans(Film film,int g,int m,int dd,int md,int dy,Sala sala, String type_seans){
        super(film);
        this.day=new Day(dd,md,dy);
        this.hour= new Hour(g,m);
        this.sala=new Sala(sala);
        this.type_seans=type_seans;
        number_of_seans++; 
    }
    public Seans(Seans seans){
        this.day=seans.day;
        this.hour=seans.hour;
        this.sala=seans.sala;
        this.type_seans=seans.type_seans;
        number_of_seans++;
    }
    @Override
    protected void finalize(){
        sala=null;
        hour=null;
        day=null;
        number_of_seans--;
    }
    
    public static int get_number_of_seans(){
        return number_of_seans;
    }
	
    public void set_hour(Hour hour){
        this.hour.set_hour(hour.get_hour_g(),hour.get_hour_m());

    }
    public void set_sala(Sala sala){
        this.sala=null;
        this.sala=new Sala(sala);
    }
    public void set_type_seans(String type_seans){
        this.type_seans=type_seans;
    }
    public void set_day(Day day){
        this.day.set_day(day.get_day_d(), day.get_day_m(), day.get_day_y());
    }
    public Day get_day(){
        return day;
    }
    public Hour get_hour(){
        return hour;
    }
    public int get_number_of_hall(){
        return sala.get_number();
    }
    public Sala get_sala(){
        return sala;
    }
    public String get_type_seans(){
        return type_seans;
    } 
    public void view_seans(){
        System.out.print(day.get_day_d()+"."+day.get_day_m()+"."+day.get_day_y()+"r ");
        System.out.print(hour.get_hour_g()+":"+hour.get_hour_m()+" ");
        System.out.print(this.get_title()+" "+this.type_seans+" "+this.get_time()+"min +"+this.get_restrictions()+" ");
        System.out.print("sala:"+(sala.get_number()+1));
    }
}
