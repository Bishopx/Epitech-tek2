type day = Monday | Tuesday | Wednesday | Thursday | Friday | Saturday | Sunday;;
type month = January | February | March | April | May | June | July | Aout | September | October | November | December;;

type date = (day * int * month * int);;

let next_day = function
	| Monday -> Tuesday
	| Tuesday -> Wednesday
	| Wednesday -> Thursday
	| Thursday -> Friday
 	| Friday -> Saturday
 	| Saturday -> Sunday
 	| Sunday -> Monday
;;

let next_month = function
	| January -> February
	| February -> March
	| March -> April
	| April -> May
 	| May -> June
 	| June -> July
 	| July -> Aout
 	| Aout -> September
 	| September -> October
 	| October -> November
 	| November -> December
 	| December -> January
;;

let is_bissextile year =
	if year mod 400 = 0 then true else
	if year mod 4 = 0 && year mod 100 != 0 then true else false
;;

let nb_days year month = match month with
	| January -> 31
	| February -> if is_bissextile year then 29 else 28 
	| March -> 31
	| April -> 30
 	| May -> 31
 	| June -> 30
 	| July -> 31
 	| Aout -> 31
 	| September -> 30
 	| October -> 31
 	| November -> 30
 	| December -> 31
;;

let next_nday jour month year = 
	if nb_days year month = jour then (1 , true) else ((jour+1) , false)
;;

let next (day, day_int, month, year) =
	if next_nday day_int month year = (1, true) && month = December then (next_day day, 1, next_month month, (year+1)) else
	if next_nday day_int month year = (1, true) then (next_day day, 1, next_month month, year) else (next_day day, (day_int+1), month, year)
;;
