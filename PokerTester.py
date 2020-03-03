#This module contains code from
#Think Python by Allen B. Downey
#http://thinkpython.com
#Copyright 2012 Allen B. Downey
#License: GNU GPLv3 http://www.gnu.org/licenses/gpl.html

#Revised & Edited by Iradiel Manzanilla Torres
#05/09/2018


from PokerHand import PokerHand
from Deck import Deck
from Hand import Hand

def findDefiningClass(obj, methodName):
#   Finds and returns the class object that will provide 
#   the definition of method_name (as a string) if it is
#   invoked on obj.
#   obj: any python object
#   method_name: string method name
    for ty in type(obj).mro():
        if methodName in ty.__dict__:
            return ty
    return None

def main():

    deck = Deck()
    deck.shuffle()

    hand = Hand()
    # deal the cards and classify the hands
    for i in range(7):
        hand = PokerHand()
        deck.moveCards(hand, 7)
        hand.sort()
        print (hand)
        hand.rankHist()
        hand.suitHist()
        
        if hand.hasStraightFlush():
            print("================Straight Flush") 
        elif hand.hasFourOfAKind():
            print("================Four Of A Kind")  
        elif hand.hasFullHouse():
            print("================Full House")
        elif hand.hasFlush():
            print("================Flush")
        elif hand.hasStraight():    
            print("================Straight")
        elif hand.hasThreeOfAKind():
            print("================Three Of A Kind")
        elif hand.hasTwoPair():
            print("================Two Of A Pair")
        elif hand.hasPair():
            print("================Pair")         
        else:
            print("================You got to know when to fold em")
            
main()    