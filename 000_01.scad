
//Spessore parete del corridoio, con la porta
spessore_uno=5; 
//lunghezza della prima parete
lunghezza_uno=36; 

//spessore parete divisoria degli ambienti
spessore_due=5;
lunghezza_due = 170; 
//
//altezza uguale per tutte le pareti
altezza=75; 


//dati relativi alla porta
altezza_porta = 25; 
larghezza_porta = 12;
//distanza della porta a partire dall'angolo esterno
distanza_porta = 14;

//parametri relativi alle finestre, ma non ancora inseriti nel modello
lunghezza_fin=15;
 altezza_fin=11;

due_pareti_porta();


//con questa funzione si creano due pareti ad angolo retto
module due_pareti(){
   union(){
   translate([-lunghezza_due,0,0]){ cube([lunghezza_due, spessore_due, altezza]);
   }
   rotate([0,0,90])    cube([lunghezza_uno, spessore_uno, altezza]);
    translate([-lunghezza_due/3,spessore_due/2,-3])cylinder(10, 1.5,1.5, $fn=50);
    translate([-lunghezza_due+10,spessore_due/2,-3])cylinder(10, 1.5,1.5, $fn=50);
   }
}


module due_pareti_porta(){
    
    difference(){
        due_pareti();
        translate([-spessore_due,distanza_porta,0]) cube([spessore_due,larghezza_porta,altezza_porta]);
    
        rotate ([0,0,90])translate([0,7,0]) cube([spessore_due,larghezza_porta,altezza_porta]);
        
        rotate ([0,0,90])translate([0,150,0]) cube([spessore_due,larghezza_porta,altezza_porta]);
     }
}

module finestra(){
    
    cube([lunghezza_fin, spessore, altezza_fin]);
    
    }
    
    
    