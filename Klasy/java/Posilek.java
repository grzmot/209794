/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package javaapplication2;

/**
 *
 * @author Maciej
 */
public class Posilek {
    private int cal;
    private String name;
    private static int count = 0;
    public Posilek()
    {
        name="";
        count++;
        cal = 0;
    }
    public Posilek(Posilek posilek)
    {
        count++;
        cal = posilek.cal;
        name=posilek.name;
    }
    public Posilek(int cal,String name)
    {
        count++;
        this.cal = cal;
        this.name=name;
    }
    protected void finalize()
    {
        count--;
    }
    public int get_cal()
    {
        return cal;
    }
    public String get_name()
    {
        return name;
    }
    public void set_cal(int cal)
    {
        this.cal=cal;
    }
     public void set_name(String name)
    {
        this.name=name;
    }
    public static int getCount()
    {
        return count;
    }
}
