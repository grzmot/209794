/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Maciej
 */
public class Day {
    private  int d;
	private  int m;
	private  int y;
        
        public Day(){
      
        }
        public Day(int d,int m, int y){
            this.d=d;
            this.m=m;
            this.y=y;
        }
        public void set_day(int d,int m,int y){
        this.d=d;
        this.m=m;
        this.y=y;
        }
        public int get_day_d(){
            return d;
        }
        public int get_day_m(){
            return m;
        }
        public int get_day_y(){
            return y;
        }
}
