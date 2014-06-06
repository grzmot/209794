/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Maciej
 */
public class Hour {
    private int g;
    private int m;
    
    public Hour()    {
        
    }
    public Hour(int g,int m){
            this.g=g;
            this.m=m;
        }
    public void set_hour(int g,int m){
        this.g=g;
        this.m=m;
    }
    public int get_hour_g(){
        return g;
    }
    public int get_hour_m(){
        return m;
    }
}
