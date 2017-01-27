let l = List.tl (Array.to_list Sys.argv);;
let is_in str = if str = "-e" then true else false
let is_in2 str = if str = "-e" then false else true
let x = Pervasives.open_in (List.hd l);;
let y = Pervasives.read_line;;


let cat filename = 
let in_channel = open_in filename in
try
  while true do
    let line = input_char in_channel in
    print_char line;
  done
with End_of_file ->
  close_in in_channel

let cat2 filename = 
let in_channel = open_in filename in
try
  while true do
    let line = input_char in_channel in
    begin
    	if line = '\n' then print_char '$';
    	print_char line;
	end
  done
with End_of_file ->
  close_in in_channel

let _ = 
	if List.exists is_in l 
	then
		let l2 = List.filter is_in2 l in
		List.iter cat2 l2
	else List.iter cat l
;;