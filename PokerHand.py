#This module contains code from
#Think Python by Allen B. Downey
#http://thinkpython.com
#Copyright 2012 Allen B. Downey
#License: GNU GPLv3 http://www.gnu.org/licenses/gpl.html

#Revised & Edited by Iradiel Manzanilla Torres
#05/09/2018


from Card import Card
from Hand import Hand

class PokerHand(Hand):

    def suitHist(self):
#        Builds a histogram of the suits that appear in the hand.
#        Stores the result in attribute suits.
        
        self._suits = {}
        for card in self._cards:
            self._suits[card._suit] = self._suits.get(card._suit, 0) + 1

    def rankHist(self):
#       Builds a histogram of the ranks that appear in the hand.
#       Stores the result in attribute ranks.

        self._ranks = {}
        for card in self._cards:
            self._ranks[card._rank] = self._ranks.get(card._rank, 0) + 1

    def hasPair(self):
        for val in self._ranks.values():
            if val == 2:
                return True
        return False
    
    def hasTwoPair(self):
        counter=0
        for val in self._ranks.values():
            if val == 2:
                counter+=1
            if counter == 2:
                return True
        return False    
      
    def hasThreeOfAKind(self):
        for val in self._ranks.values():
            if val == 3:
                return True
        return False   
    
    def hasFourOfAKind(self):
        for val in self._ranks.values():
            if val == 4:
                return True
        return False          
        
    def hasStraight(self):
        prevRank = 0
        count = 0
        for card in self._cards:
            if card._rank == prevRank + 1:
                count +=1
            else:
                count = 0              
            prevRank = card._rank
        if count >=5:
            return True
        else:
            return False        
    
    def hasFullHouse(self):
            if self.hasPair() and self.hasThreeOfAKind():
                return True
            else:
                return False
            
    def hasFlush(self):
        for val in self._suits.values():
            if val >= 5:
                return True
        return False    
            
    def hasStraightFlush(self):
        prevRank = 0
        prevSuit = 0
        count = 0
        for card in self._cards:
            if card._rank == prevRank + 1:       
                if card._suit == prevSuit:
                    count +=1   
                else:
                    count = 0                  
            else:
                count = 0
                      
            prevRank = card._rank
            prevSuit = card._suit
        if count >=5:
            return True
        else:
            return False