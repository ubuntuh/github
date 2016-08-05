#!/usr/bin/env ruby
# coding: utf-8
class Dictionary
  def initialize
    @random = []
    open('dics/random.txt') do |f| # ランダム辞書を読み込む。
      f.each do |line|
        line.chomp! # 末尾の改行を捨てる。
        next if line.empty? # 空行は無視する。
        @random.push(line)
      end
    end

    @pattern = []
    open('dics/pattern.txt') do |f|
      f.each do |line|
        pattern, phrases = line.chomp.split("\t") # chomp で末尾の改行を捨てる。split でタブで分割する。
        next if pattern.nil? or phrases.nil? # 以上データを無視し、pattern と phrases を限定する。
        @pattern.push({'pattern'=>pattern, 'phrases'=>phrases}) # ハッシュを完成させていく。
      end
    end
  end

  attr_reader :random, :pattern
end
