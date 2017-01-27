(****************************************************************************)
(*                                                                          *)
(*                      main.ml in langage_de_modules                       *)
(*                      For Epitech's λ Knowledge Unit                      *)
(*                      Made by: David GIRON                                *)
(*                                                                          *)
(****************************************************************************)

let av = Sys.argv;;

type wall = UP | RIGHT | DOWN | LEFT;;

if (Array.length av == 1) then Printf.printf "pas mal\n" else
if (Array.length av == 5) then Printf.printf "faut tout faire\n" else
Printf.printf "Cest pas bon\n";;

let rec get_row av i = match (Array.get av i) with
	| "-r" -> Array.get av (i + 1)
	| _    -> get_row av (i + 1)
;;

let rec get_col av i = match ((Array.get av i), i) with
	| ("-c", _) -> Array.get av (i + 1)
	| (_, _)    -> get_col av (i + 1)
;;

let myMin x y =
	if (x <= y) then x else y
;;

let myMax x y =
	if (x >= y) then x else y
;;

let rec init_list l size width = match size with
	| 0 	-> l
	| _   	-> 
		let lis = [Maze.Case.new_case false true true size ((size - 1) mod width) ((size - 1)/width) 0] in
		init_list (List.append l lis) (size - 1) width
;;

let rec change_id maze small_id big_id i =
	if (i == List.length maze) then maze
	else 
		if (Maze.Case.get_id (List.nth maze i) == big_id) then
		(
			Maze.Case.set_id (List.nth maze i) small_id;
			change_id maze small_id big_id (i+1)
		)
		else change_id maze small_id big_id (i+1)
;;
	
let rec find_x_y maze x y i =
	if (i == List.length maze) then (-1)
	else
		if (Maze.Case.get_y (List.nth maze i) == y && Maze.Case.get_x (List.nth maze i) == x)
		then
		( 
			Maze.Case.get_id (List.nth maze i)
		)
		else find_x_y maze x y (i + 1)
;;

let check_and_open maze randx randy randw =
	if (randw == 2) then
		if (((find_x_y maze randx randy 0) == (find_x_y maze randx (randy + 1) 0)) || randy >= 4) then 
		(
			maze
		)
		else
			(
			Printf.printf "La %d %d = %d <=> %d\n" randx randy (find_x_y maze randx randy 0) (find_x_y maze randx (randy+1) 0);
			Printf.printf "Min = %d\n" (myMin (find_x_y maze randx randy 0) (find_x_y maze randx (randy+1) 0));
			Maze.Case.set_dwall (List.nth maze ((find_x_y maze randx randy 0) - 1)) false;
			Maze.Case.set_open (List.hd maze) (Maze.Case.get_open (List.hd maze) + 1);
			let maze = change_id maze (myMin (find_x_y maze randx randy 0) (find_x_y maze randx (randy+1) 0)) (myMax (find_x_y maze randx randy 0) (find_x_y maze randx (randy+1) 0)) 0 in
			maze	
			)
	else if (randw == 1) then
		if (((find_x_y maze randx randy 0) == (find_x_y maze (randx + 1) randy 0)) || randy >= 4) then maze
		else
			(
			Printf.printf "ICI %d %d = %d <=> %d\n" randx randy (find_x_y maze randx randy 0) (find_x_y maze randx (randy+1) 0);
			Printf.printf "Min = %d\n" (myMin (find_x_y maze randx randy 0) (find_x_y maze randx (randy+1) 0));
			Maze.Case.set_rwall (List.nth maze ((find_x_y maze randx randy 0) - 1)) false;
			Maze.Case.set_open (List.hd maze) (Maze.Case.get_open (List.hd maze) + 1);			
			let maze = change_id maze (myMin (find_x_y maze randx randy 0) (find_x_y maze randx (randy+1) 0)) (myMax (find_x_y maze randx randy 0) (find_x_y maze randx (randy+1) 0)) 0 in
			maze				
			)
	else
		maze
;;


let openwall maze randx randy randw x y = 
	if ((randx == 0 && randw == 3) || (randy == 0 && randw == 0)
	|| (randx == (x - 1) && randw == 1) || (randy == (y - 1) && randw == 2))
	then maze
	else if (randw == 3) then check_and_open maze (randx - 1) randy 1
	else if (randw == 0) then check_and_open maze randx (randy - 1) 2
	else check_and_open maze randx randy randw
;;

let rec maze_gen maze x y stop =
	if (Maze.Case.get_open (List.hd maze) ==  stop) then maze
	else 
		let randx = Random.int x and randy = Random.int y and randw = Random.int 4 in
		let help_maze = openwall maze randx randy randw x y in
		maze_gen help_maze x y stop 	
;;

Random.self_init ();;
let maze = List.rev (init_list [] 25 5);;
Printf.printf "Find = %d\n" (find_x_y maze 0 0 0);;
let maze2 = maze_gen maze 5 5 24;;
(* Maze.Case.set_id (List.nth maze 24) 2;;
Maze.Case.set_id (List.nth maze 23) 2;;
Maze.Case.set_id (List.nth maze 22) 2;;
let maze2 = change_id maze 1 2 0;; *)
(* Maze.Case.set_id (List.nth maze2 12) 1;; *)
Printf.printf "Id = %d\n" (find_x_y maze2 0 0 0);;
Printf.printf "Id = %d\n" (find_x_y maze2 1 0 0);;
Printf.printf "Id = %d\n" (find_x_y maze2 2 0 0);;
Printf.printf "Id = %d\n" (find_x_y maze2 3 0 0);;
Printf.printf "Id = %d\n" (find_x_y maze2 4 0 0);;
Printf.printf "Id = %d\n" (find_x_y maze2 0 1 0);;
Printf.printf "Id = %d\n" (find_x_y maze2 1 1 0);;
Printf.printf "Id = %d\n" (find_x_y maze2 2 1 0);;
Printf.printf "Id = %d\n" (find_x_y maze2 3 1 0);;
Printf.printf "Id = %d\n" (find_x_y maze2 4 1 0);;
Printf.printf "Id = %d\n" (find_x_y maze2 0 2 0);;
Printf.printf "Id = %d\n" (find_x_y maze2 1 2 0);;
Printf.printf "Id = %d\n" (find_x_y maze2 2 2 0);;
Printf.printf "Id = %d\n" (find_x_y maze2 3 2 0);;
Printf.printf "Id = %d\n" (find_x_y maze2 4 2 0);;
(* Printf.printf "Id = %d\n" (find_x_y maze2 4 4 0);;
Printf.printf "Id = %d\n" (find_x_y maze2 3 4 0);;
Printf.printf "Id = %d\n" (find_x_y maze2 2 4 0);; *)
Printf.printf "%s\n" (get_row av 1);;
(* let main () =
  	let zaz = Maze.Case.new_case false false false 3 3 3 and
  	ex = Maze.Case.new_case true true true 2 2 2
  	in let guillaume = ex::zaz::[] in
    begin
      (* Assistants.Koala.print zaz; *)
      Maze.Case.print (List.hd guillaume)
    end
;; *)

(****************************************************************************)
(* let _ = main () *)
