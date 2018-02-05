#!/usr/bin/env ruby

##
# Suits: Spades (1), Hearts (2), Clubs (3), Diamons (4)
# Ranks: King (13), Queen (12), Jack (11), 10, 9, Ace (14)
class Card
  attr_reader :suit
  attr_reader :rank

  def initialize(suit, rank)
    @suit = suit
    @rank = rank
  end

  def self.all
    cards = []
    for suit in (1..4).to_a
      for rank in (9..14).to_a
        cards.push Card.new(suit, rank)
      end
    end
    cards
  end
end

##
# Returns array of arrays. First 4 arrays are hands,
# the 5th array is the pool
def deal(cards)
  hands = []
  cards.shuffle
  for i in 0..4 #1 to 5
    hands[i] = cards.pop(5)
  end
  hands
end
