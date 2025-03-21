class Solution {
    boolean canSolve(String recipy, HashSet<String> have, HashMap<String, List<String>> need) {
        if (have.contains(recipy)) return true;
        boolean check = true;

        if (need.containsKey(recipy) == false) return false;
        // System.out.println(need);
        for (String ele : need.get(recipy)) {
            if (!canSolve(ele, have, need)) {
                check = false;
            }
        }
        if (check == true) {
            have.add(recipy);
        }
        return check;
    }    

    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        HashMap<String, List<String>> need = new HashMap<>();
        int n = recipes.length;
        for (int i = 0; i < n; i++) {
            need.put(recipes[i], ingredients.get(i));
        }
        System.out.println(need);
        HashSet<String> have = new HashSet<>();
        for (String supply : supplies) {
            have.add(supply);
        }
        List<String> ans = new ArrayList<>();
        for (String recipy : recipes) {
            if (canSolve(recipy, have, need)) {
                ans.add(recipy);
            }
        }
        return ans;
    }
}