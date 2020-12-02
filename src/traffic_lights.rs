#[allow(unused_imports)]
use std::cmp::{min,max};
use std::collections::BTreeSet;
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

fn neighbors(tree: &BTreeSet<u64>, val: u64) -> (Option<&u64>, Option<&u64>) {
    use std::ops::Bound::*;

    let mut before = tree.range((Unbounded, Excluded(val)));
    let mut after = tree.range((Excluded(val), Unbounded));

    (before.next_back(), after.next())
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());
    
    let x = scan.next::<u64>();
    let n = scan.next::<u64>();
    let a: Vec<u64> = (0..n).map(|_| scan.next()).collect();

    let mut positions: BTreeSet<u64> = BTreeSet::new();
    positions.insert(0);
    positions.insert(x);

    let mut lengths: BTreeSet<u64> = BTreeSet::new();
    lengths.insert(x);


    for pos in &a {
        // find the number smaller than pos

        let (prev, next) = neighbors(&positions, *pos);

        // access loc, loc+1

        let nextVal = next.unwrap();
        let prevVal = prev.unwrap();

        let length = nextVal - prevVal;

        
        // remove eff_val from lengths and insert two shorter lengths
        lengths.remove(&length);

        lengths.insert(pos - prevVal);
        lengths.insert(nextVal - pos);

        // print the last element in lengths 
        write!(out, "{}", lengths.pop_last().unwrap());
    }
}
