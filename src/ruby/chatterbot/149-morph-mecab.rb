#!/usr/bin/env ruby
# coding: utf-8
require "open3"
require 'MeCab'

module Morph
  def init_analyzer
    @tagger = MeCab::Tagger.new('--node-format %m\s%f[0]-%f[1]\t')
  end

  def analyze(text)
    analyzed = @tagger.parse(text)
    splitted = analyzed.chomp.split(/\t/)
    lists = splitted.map do |part|
      part.split(/ /)
    end
    lists.delete(["EOS"])
    return lists
  end

  def keyword?(part)
    return /名詞-(一般|固有名詞|サ変接続|形容動詞語幹)/ =~ part
  end
  
  module_function :init_analyzer, :analyze, :keyword?
end

if $0 == __FILE__
  Morph::init_analyzer
  text = '茶筌は、形態素解析ツールのひとつ。奈良先端科学技術大学院大学松本研究室で開発された。'
  result = Morph::analyze(text)
  print(result)
  puts
end
