
/*questa funzione restituisce un arco che poi andrà sottratto alla parete di cui fa parte*/


//spessore della parete
spessore = 2;
//altezza dell'arco
altezza = 10;
//più è alto il numero maggiore sarà la deformazione dell'ellisse
scala=2;

base_arco();


module base_arco(){
difference(){
scale([1,1,2])rotate([90,0,0])cylinder(r1=altezza, r2= altezza, h= spessore);
 rotate([90,0,0])translate([-altezza,-2*altezza,0])cube([2*altezza,2*altezza,spessore]); 

}
}