#[allow(unused_imports)]
use std::cmp::{min,max};
use std::io::{BufWriter, stdin, stdout, Write};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());
    
    let x = scan.next::<usize>();
    let n = scan.next::<usize>();
    let a: Vec<usize> = (0..n).map(|_| scan.next()).collect();

    writeln!(out, "{}", x);

    writeln!(out, "{}", n);


    writeln!(out, "{:#?}", a);

    writeln!(out, "Yes").ok();
}
