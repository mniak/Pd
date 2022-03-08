local patch = pd.Class:new():register("pitch")

function patch:initialize(sel, atoms)
   self.outlets = 1
   if type(atoms[1]) == "string" and atoms[1] == "class" then
      self.mode = "class"
      self.inlets = 2
   else
      self.mode = "full"
      self.inlets = 3
   end

   self.step = 0
   self.alteration = 0
   self.octave = 4

   self["in_n_pitch-class"] = self.in_n_pitch_class
   return true
end

function patch:in_1_bang()
   -- Normalize values
   self.step = self.step % 7
   self.octave = math.min(math.max(self.octave, 0), 10)
   self.alteration = math.min(math.max(self.alteration, -2), 2)

   if self.mode == "class" then
      self:outlet(1, "pitch-class", {self.step, self.alteration})
   else
      self:outlet(1, "pitch", {self.step, self.alteration, self.octave})
   end
end

function patch:in_1_float(step)
   self.step = step
   self:in_1_bang()
end

function patch:in_2_float(alteration)
   self.alteration = alteration
end

function patch:in_3_float(octave)
   self.octave = octave
end

function patch:in_n_pitch(n, pitch)
   self.step = pitch[1]
   self.alteration = pitch[2]
   self.octave = pitch[3]
   if n == 1 then 
      self:in_1_bang()
   end
end

function patch:in_n_pitch_class(n, pitchclass)
   self.step = pitchclass[1]
   self.alteration = pitchclass[2]
   if n == 1 then 
      self:in_1_bang()
   end
end
